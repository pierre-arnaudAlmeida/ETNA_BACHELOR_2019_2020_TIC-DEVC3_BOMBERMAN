volatile sig_atomic_t flag = 0;
int sockfd = 0;
server *server_data;
server *server_data2;
int dir;

/*
  Permet de récuperer les informations liéà la structure du jeu
*/
server* get_client_data()
{
  return server_data;
}

/*
  Permet de mettre à jour la structure du jeu dans la classe client
*/
void set_client_data(server *new_server_data)
{
  server_data = new_server_data;
}

/*
  Permet de récupérer la direction ou l'action que souhaite faire le joueur pour l'envoyer au serveur
*/
void set_direction(int new_direction)
{
  dir = new_direction;
}

/*
  Permet de récupérer la concaténation des touches ctrl + c ou bien l'action de fermet la fenêtre
*/
void catch_ctrl_c_and_exit(int sig)
{
  flag = 1;
}

/*
  Permet d'envoyer au serveur que la partie va commencer
*/
void send_start_msg()
{
  write(sockfd, "START", strlen("START"));
}

/*
  Permet d'envoyer au serveur une demande pour se déplacer/quitter/poser la bombe
  De manière continue durant toute la partie (un thread)
*/
void send_msg_handler()
{
  char buffer[BUFFER_SIZE] = {};
  int receive = 0;
  bool running = true;

  while (running) {
      if (server_data->game.game_state == 1) {
        switch (dir) {
          case 1:
            write(sockfd, "UP", strlen("UP"));
            dir = 0;
            break;
          case 2:
            write(sockfd, "DOWN", strlen("DOWN"));
            dir = 0;
            break;
          case 3:
            write(sockfd, "LEFT", strlen("LEFT"));
            dir = 0;
            break;
          case 4:
            write(sockfd, "RIGHT", strlen("RIGHT"));
            dir = 0;
            break;
          case 5:
            write(sockfd, "BOMB", strlen("BOMB"));
            dir = 0;
            break;
          case 99:
            write(sockfd, "EXIT", strlen("EXIT"));
            dir = 0;
            running = false;
            break;
        }
      }
  }
  catch_ctrl_c_and_exit(2);
}

/*
  Permet de recevoir les messages envoyé par le serveur avant et pendant la partie
  (un thread)
*/
void recv_msg_handler()
{
  int receive;
  server_data2 = server_data;
  while (1) {
	  receive = recv(sockfd, server_data2, sizeof(struct server), 0);
    if (receive > 0) {
      set_client_data(server_data2);
    } else if (receive == 0 || strcmp(server_data2->message, "EXIT") == 0) {
			break;
    }
  }
}

/*
  Permet d'initialiser le client, permettre la connexion du client au serveur avec son adresse ip et ses informations d'identification
  (un thread)
  Lance le thread d'envoie de message et le thread de réception de message de la part du serveur
*/
void *handle_main_client(void *arg)
{
  server_data = (server *)arg;
  int err;
  int id;

  signal(SIGINT, catch_ctrl_c_and_exit);

  struct sockaddr_in server_addr;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(server_data->ip);
  server_addr.sin_port = htons(server_data->port);

  err = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (err == -1) {
    perror("ERROR CLIENT: connect");
    return NULL;
	}

  id = server_data->player.player_id;
	send(sockfd, server_data->player.name, 32, 0);
  send(sockfd, &id, sizeof(id), 0);
  
  pthread_t send_msg_thread;
  if (pthread_create(&send_msg_thread, NULL, (void *) send_msg_handler, NULL) != 0) {
	  perror("ERROR CLIENT: send_msg_thread");
    return NULL;
	}
  
	pthread_t recv_msg_thread;
  if (pthread_create(&recv_msg_thread, NULL, (void *) recv_msg_handler, NULL) != 0) {
		perror("ERROR CLIENT: recv_msg_thread");
		return NULL;
	}
  
	while (1) {
		if (flag)
			break;
	}

	close(sockfd);
	return NULL;
}
