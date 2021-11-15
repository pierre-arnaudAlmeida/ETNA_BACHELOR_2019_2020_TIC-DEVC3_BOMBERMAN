/*
    Affiche les touches essentielles au jeu pour un client
    On met le client en attente avant le début de la partie qui sera donner par le serveur
*/
int display_key_tips_client(display *display, server *server_data)
{
    bool waiting = true;
    SDL_Event event;
    char str[PORT_LENGHT + 1];
    server *serv;

    while (waiting) {
        serv = get_client_data();
        server_data->game = serv->game;
        server_data->connfd = serv->connfd;

        if (server_data->game.game_state)
            return 0;

        SDL_SetRenderDrawColor(display->renderer, 0, 200, 50, 1);
        SDL_RenderClear(display->renderer);

        display_text(display->renderer, TEXT_KEY_TIPS, 40, -1, 50, PATH_FONT_BOLD);
        display_text(display->renderer, TEXT_KEY_UP, 15, -1, 150, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_DOWN, 15, -1, 170, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_LEFT, 15, -1, 190, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_RIGHT, 15, -1, 210, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_SPACE, 15, -1, 230, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_SURREND, 15, -1, 250, PATH_FONT);
        display_text(display->renderer, TEXT_WAIT_START, 15, -1, 400, PATH_FONT);

        SDL_RenderPresent(display->renderer);

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return 1;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                       return 1;
                    break;
            }
        }
    }
    return 0;
}
