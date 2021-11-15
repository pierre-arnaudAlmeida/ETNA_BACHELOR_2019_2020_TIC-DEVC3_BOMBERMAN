/*
    Initialise une partie
    Au début une partie contient un joueur, celui qui crée la partie et ensuite cela augmentera en fonction des personnes
    qui rejoignent la partie
    Ensuite le temps que la partie n'est pas arreter/terminer on récupère les entrées clavier et on affiche le plateau
*/
void init_game(display *display, game *game, player *player)
{
    char ip[IP_LENGHT];
    char *ip_player;
    server *server_data;

    send_start_msg();
    usleep(50000);
    display_map(display, game);

    get_ip(ip);
    for (int i = 0; i < MAX_PLAYERS; i++) {
        memset(ip_player, 0, sizeof(ip_player));
        to_str_player_address(ip_player, game->player_list[i].address);
        if (strcmp(ip, ip_player) == 0 && player->player_id == game->player_list[i].player_id) {
            player = &game->player_list[i];
        }
    }
    
    while (game->game_state == 1) {
        get_mouvement(game, player);
        SDL_Delay(50);
        display_map(display, game);
    }
}
