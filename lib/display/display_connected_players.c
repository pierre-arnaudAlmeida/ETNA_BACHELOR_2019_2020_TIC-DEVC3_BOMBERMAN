/*
    Affiche l'adresse ip et le port du serveur
    Affiche les joueurs connectés en temps réel
    Récupère les entrées clavier pour faire débuter la partie.
    On vérifie le nombre de clients connectés avant de pouvoir lancer la partie.
    Le nombre minimum de joueurs pour lancer une partie est définis dans le fichier constante
*/
int display_connected_players(display *display, server *server_data)
{
    bool waiting = true;
    SDL_Event event;
    char str[PORT_LENGHT + 1];
    
    while (waiting) { 
        server *serv = get_server_data();
        server_data->game = serv->game;
        server_data->connfd = serv->connfd;
        to_string(str, server_data->port);

        SDL_SetRenderDrawColor(display->renderer, 0, 200, 50, 1);
        SDL_RenderClear(display->renderer);

        display_text(display->renderer, TEXT_START, 40, -1, 50, PATH_FONT_BOLD);
        display_text(display->renderer, TEXT_JOIN_IP, 15, -1, 120, PATH_FONT);
        display_text(display->renderer, server_data->ip, 15, -1, 140, PATH_FONT);
        display_text(display->renderer, TEXT_JOIN_PORT, 15, -1, 160, PATH_FONT);
        display_text(display->renderer, str, 15, -1, 180, PATH_FONT);

        display_text(display->renderer, TEXT_CONECTED_PLAYER, 20, -1, 210, PATH_FONT);
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (server_data->game.player_list[i].player_id != 0) {
                display_text(display->renderer, server_data->game.player_list[i].name, 15, -1, 240 + (i * 40), PATH_FONT);
                memset (str, 0, sizeof (str));
                to_str_player_address(str, server_data->game.player_list[i].address);
                display_text(display->renderer, str, 15, -1, 260 + (i * 40), PATH_FONT);
            }
        }
        display_text(display->renderer, TEXT_KEY_ENTER, 15, -1, 420, PATH_FONT);

        SDL_RenderPresent(display->renderer);

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return 1;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                       return 1;
                    } else if (event.key.keysym.sym == SDLK_KP_ENTER || event.key.keysym.sym == SDLK_RETURN) {
                        if (check_player_connected(server_data->game) == 0) {
                            server_data->game.game_state = 1;
                            return 0;
                        }
                    }
                    break;
            }
        }
    }
    return 0;
}
