/*
    Affiche les touches essentielles au jeu pour le propriétaire du serveur
    Permet aussi au propriétaire de définir le port sur lequel le serveur se lancera
    avec une vérification si le port est disponnible ou non avant la validation
*/
int display_key_tips_server(display *display, server *server_data)
{
    bool waiting = true;
    bool clear_screen = true;
    char port[PORT_LENGHT + 1] = "";
    char error_message[STR_MAX_SIZE] = "";
    SDL_Event event;

    memset (server_data->ip, 0, sizeof (server_data->ip));
    get_ip(server_data->ip);
	if (strcmp(server_data->ip, "") == 0)
		add_new_char_to_str(server_data->ip, IP_LENGHT, 1, DEFAULT_IP);
        
    while (clear_screen) { 
        SDL_SetRenderDrawColor(display->renderer, 0, 200, 50, 1);
        SDL_RenderClear(display->renderer);

        SDL_Rect rectangle = {180, 310, 150, 30};
        draw_rect(display, rectangle);

        display_text(display->renderer, TEXT_KEY_TIPS, 40, -1, 50, PATH_FONT_BOLD);
        display_text(display->renderer, TEXT_KEY_UP, 15, -1, 150, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_DOWN, 15, -1, 170, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_LEFT, 15, -1, 190, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_RIGHT, 15, -1, 210, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_SPACE, 15, -1, 230, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_SURREND, 15, -1, 250, PATH_FONT);
        display_text(display->renderer, TEXT_INTRO_PORT, 15, -1, 280, PATH_FONT);
        display_text(display->renderer, port, 15, -1, 315, PATH_FONT);
        if (strcmp(error_message, "") != 0)
            display_text(display->renderer, error_message, 15, -1, 350, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_ENTER, 15, -1, 400, PATH_FONT);
        SDL_RenderPresent(display->renderer);

        waiting = true;
        memset (error_message, 0, sizeof (error_message));

        while (waiting) {
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        return 1;
                        break;
                    case SDL_TEXTINPUT:
                        add_new_char_to_str(port, PORT_LENGHT, 1, event.text.text);
                        waiting = false;
                        break;
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_ESCAPE) {
                            return 1;
                        } else if (event.key.keysym.sym == SDLK_KP_ENTER || event.key.keysym.sym == SDLK_RETURN) {
                            if (is_int(port)) {
                                server_data->port = atoi(port);
                                if (check_sock(server_data) == 0) {
                                    return 0;
                                } else {
                                    add_new_char_to_str(error_message, STR_MAX_SIZE, 1, PORT_ERROR_USED);
                                    waiting = false;
                                }
                            } else {
                                add_new_char_to_str(error_message, STR_MAX_SIZE, 1, PORT_ERROR_FORMAT);
                                waiting = false;
                            }
                        } else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                            str_remove_last_char(port);
                            waiting = false;
                        }
                        break;
                }
            }
        }
    }
    return 0;
}
