static _Atomic unsigned int player_count = 0;
static int uid = 10;
player *players[MAX_PLAYERS];
pthread_mutex_t players_mutex = PTHREAD_MUTEX_INITIALIZER;
server *server_data;

/*
	Récupère les informations de la structure du jeu de la classe serveur
*/
server* get_server_data()
{
	return server_data;
}

/*
	Permet de modifier les valeurs de la structure du jeu de la classe serveur
*/
void set_server_data(server *new_server_data)
{
	server_data = new_server_data;
}

/*
	Ajoute au tableau un client à la liste des clients connecter
*/
void add_client(player *_player)
{
	pthread_mutex_lock(&players_mutex);
	for (int i = 0; i < MAX_PLAYERS; i++) {
		if (!players[i]) {
			players[i] = _player;
			break;
		}
	}
	pthread_mutex_unlock(&players_mutex);
}

/*
	Retire du tableau le clients qui viens de se déconnecter
*/
void queue_remove(int uid)
{
	pthread_mutex_lock(&players_mutex);
	for (int i = 0; i < MAX_PLAYERS; i++) {
		if (players[i]) {
			if (players[i]->player_id == uid) {
				players[i] = NULL;
				break;
			}
		}
	}
	pthread_mutex_unlock(&players_mutex);
}

/*
	Envoi la strcuture du jeu à toutes les personnes connectés
*/
void send_message_to_all(char *s)
{
	pthread_mutex_lock(&players_mutex);
	memset (server_data->message, 0, sizeof (server_data->message));
	add_new_char_to_str(server_data->message, BUFFER_SIZE, 1, s);
	
	for (int i = 0; i < MAX_PLAYERS; i++) {
		if (players[i]) {
			if (players[i]->player_id != uid) {
				if (send(players[i]->sockfd, server_data, sizeof(struct server),0) < 0) {
					perror("ERROR SERVER: write to descriptor failed");
					break;
				}
			}
		}
	}
	pthread_mutex_unlock(&players_mutex);
}

/*
	Envoie la structure aux clients qui on un identifiant différent de celui mis en paramètre
*/
void send_struct_to_others(char *s, int uid)
{
	pthread_mutex_lock(&players_mutex);
	memset (server_data->message, 0, sizeof (server_data->message));
	add_new_char_to_str(server_data->message, BUFFER_SIZE, 1, s);
	for (int i = 0; i < MAX_PLAYERS; i++) {
		if (players[i]) {
			if (players[i]->player_id != uid) {
				if (send(players[i]->sockfd, server_data, sizeof(struct server),0) < 0) {
					perror("ERROR SERVER: write to descriptor failed");
					break;
				}
			}
		}
	}
	pthread_mutex_unlock(&players_mutex);
}

/*
	Envoi la structure au client dont l'identifiant est en paramètre
*/
void send_struct_to_request(char *s, int uid)
{
	pthread_mutex_lock(&players_mutex);
	memset (server_data->message, 0, sizeof (server_data->message));
	add_new_char_to_str(server_data->message, BUFFER_SIZE, 1, s);
	for (int i = 0; i < MAX_PLAYERS; i++) {
		if (players[i]) {
			if (players[i]->player_id == uid) {
				if (strcmp(s, "EXIT") == 0)
					server_data->game.game_state = 0;
				if (send(players[i]->sockfd, server_data, sizeof(struct server),0) < 0) {
					perror("ERROR SERVER: write to descriptor failed");
					break;
				}
				if (strcmp(s, "EXIT") == 0)
					server_data->game.game_state = 1;
			}
		}
	}
	pthread_mutex_unlock(&players_mutex);
}

/*
	Crée un thread pour un client, il permettra de recevoir les message du serveur et de gérer la déconnection/l'abandon du joueur
*/
void *handle_client(void *arg)
{
	char buff_out[BUFFER_SIZE];
	char name[32];
	int id;
	int leave_flag = 0;
	int receive;
	player *pl = (player *)arg;
	
	player_count++;

	if (recv(pl->sockfd, name, 32, 0) <= 0) {
		leave_flag = 1;
	} else {
		recv(pl->sockfd, &id, sizeof(id), 0);
		strcpy(pl->name, name);
		for (int i = 0; i < MAX_PLAYERS; i++) {
			if (pl->player_id == server_data->game.player_list[i].player_id) {
				strcpy(server_data->game.player_list[i].name, name);
				pl->player_id = id;
				server_data->game.player_list[i].player_id = id;
			}
		}
	}
	memset(buff_out, 0, BUFFER_SIZE);

	while (1) {
		if (leave_flag)
			break;
		receive = recv(pl->sockfd, buff_out, BUFFER_SIZE, 0);
		if (receive > 0) {
			if (strlen(buff_out) > 0) {
				if (strcmp(buff_out, "UP") == 0) {
					move(&server_data->game, UP, pl);
				} else if (strcmp(buff_out, "DOWN") == 0) {
					move(&server_data->game, DOWN, pl);
				} else if (strcmp(buff_out, "LEFT") == 0) {
					move(&server_data->game, LEFT, pl);
				} else if (strcmp(buff_out, "RIGHT") == 0) {
					move(&server_data->game, RIGHT, pl);
				} else if (strcmp(buff_out, "BOMB") == 0) {
					put_bomb(&server_data->game, pl);
				} else if (strcmp(buff_out, "START") == 0) {
					server_data->game.game_state = 1;
					server_data->game.start_tick = SDL_GetTicks();
				} else if (strcmp(buff_out, "EXIT") == 0) {
					for (int i = 0; i < MAX_PLAYERS; i++)
						if (pl->player_id == server_data->game.player_list[i].player_id){
							send_struct_to_request("EXIT", pl->player_id);
							server_data->game.player_list[i].player_id = 0;
						}
					leave_flag = 1;
				}
				
				if (strcmp(buff_out, "UP") == 0 ||
        			strcmp(buff_out, "DOWN") == 0 ||
        			strcmp(buff_out, "LEFT") == 0 ||
        			strcmp(buff_out, "RIGHT") == 0 ||
					strcmp(buff_out, "BOMB") == 0 ||
					strcmp(buff_out, "START") == 0) {
					send_struct_to_others(buff_out, pl->player_id);
					send_struct_to_request("OK", pl->player_id);
				}
			}
		} else if (receive == 0) {
			for (int i = 0; i < MAX_PLAYERS; i++)
				if (pl->player_id == server_data->game.player_list[i].player_id){
					send_struct_to_request("OK", pl->player_id);
					server_data->game.player_list[i].player_id = 0;
				}
			leave_flag = 1;
		} else {
			perror("ERROR SERVER: -1");
			leave_flag = 1;
		}
		memset(buff_out, 0, BUFFER_SIZE);
	}

	close(pl->sockfd);
  	queue_remove(pl->player_id);
  	free(pl);
  	player_count--;
  	pthread_detach(pthread_self());

	return NULL;
}

/*
	Thread qui vérifie que l'état des bombes, le nombre de joueurs encore conenctés et vivant dans la parties
*/
void *handle_game(void *arg)
{
	bool running = true;
	while (running) {
		if (server_data->game.game_state == 1) {
			if (explode_bomb(&server_data->game) == 1)
				send_message_to_all("OK");
			if (check_player_alive(&server_data->game) == 1) {
				running = false;
				server_data->game.game_state = 0;
				server_data->game.game_time = 0;
				server_data->game.start_tick = 0;
				send_message_to_all("EXIT");
			}
		}
	}
	return NULL;
}

/*
	Crée un thread serveur pour permettre la conenction des différents clients à ce serveur et a chaque
	clients qui se connecte au serveur on lui crée un thread client associé
*/
void *handle_main_serveur(void *arg)
{
	server_data = (server *)arg;
  	struct sockaddr_in pl_addr;
  	pthread_t tid;
	pthread_t game;
	int count = 0;
	bool added;
	bool running = true;

	init_players(&server_data->game);
	pthread_create(&game, NULL, &handle_game, NULL);

	while (running) {
		added = false;

		socklen_t player_len = sizeof(pl_addr);
		server_data->connfd = accept(server_data->listenfd, (struct sockaddr*)&pl_addr, &player_len);
		
		if (server_data->game.game_state == false) {
			if (player_count == MAX_PLAYERS) {
				perror("ERROR SERVER: Max clients reached");
				close(server_data->connfd);
				continue;
			}

			player *pl = (player *)malloc(sizeof(player));
			pl->address = pl_addr;
			pl->sockfd = server_data->connfd;
			pl->player_id = uid++;

			add_client(pl);
			pthread_create(&tid, NULL, &handle_client, (void*)pl);

			for (int i = 0; i < MAX_PLAYERS; i++){
				if (server_data->game.player_list[i].player_id == 0 && added == false) {
					server_data->game.player_list[i].player_id = pl->player_id;
					server_data->game.player_list[i].address = pl_addr;
					sleep(1);
					added = true;
					count++;
				}
			}
		} else {
			close(server_data->connfd);
			running = false;
		}
		sleep(1);
	}
	return NULL;
}
