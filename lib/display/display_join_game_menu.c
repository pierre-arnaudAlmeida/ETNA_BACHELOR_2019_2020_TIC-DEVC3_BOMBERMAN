/*
    Permet de rentrer l'adresse ip et le port pour rejoindre une partie
    Affiche le texte, un rectangle pour savoir sur quel champs on saisie
    Verifie le format de l'ip et du port
*/
int display_join_game_menu(display *display, char *ip_connection, int *port_connection)
{
    bool waiting = true;
    bool clear_screen = true;
    SDL_Event event;
    char ip[IP_LENGHT + 1] = "";
    char ip_to_verif[IP_LENGHT + 1] = "";
    char port[PORT_LENGHT + 1] = "";
    char error_message[STR_MAX_SIZE] = "";
    int line = 0;
    int count = 0;

    while (clear_screen) {        
        SDL_SetRenderDrawColor(display->renderer, 0, 200, 50, 1);
        SDL_RenderClear(display->renderer);
        
        SDL_Rect rectangle = {180, (180 + (line * 70)), 150, 30};
        draw_rect(display, rectangle);

        display_text(display->renderer, TEXT_JOIN_GAME, 40, -1, 50, PATH_FONT_BOLD);
        display_text(display->renderer, TEXT_INTRO_IP, 15, -1, 150, PATH_FONT);
        display_text(display->renderer, ip, 15, -1, 185, PATH_FONT);
        display_text(display->renderer, TEXT_INTRO_PORT, 15, -1, 220, PATH_FONT);
        display_text(display->renderer, port, 15, -1, 255, PATH_FONT);
        if (strcmp(error_message, "") != 0)
            display_text(display->renderer, error_message, 15, -1, 300, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_TAB, 15, -1, 400, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_CONTINUE, 15, -1, 420, PATH_FONT);

        SDL_RenderPresent(display->renderer);
        
        waiting = true;
        memset (error_message, 0, sizeof (error_message));

        while (waiting) {
            memset (ip_to_verif, 0, sizeof (ip_to_verif));
            add_new_char_to_str(ip_to_verif, IP_LENGHT, 1, ip);
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        return 1;
                    case SDL_TEXTINPUT:
                        if (line == 0)
                            add_new_char_to_str(ip, IP_LENGHT, count, event.text.text);
                        else if (line == 1)
                            add_new_char_to_str(port, PORT_LENGHT, count, event.text.text);
                        waiting = false;
                        break;
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_ESCAPE) {
                            return 1;
                        } else if (event.key.keysym.sym == SDLK_KP_ENTER || event.key.keysym.sym == SDLK_RETURN) {
                            if (check_ip_port(ip_to_verif, port, error_message) == 0) {
                                add_new_char_to_str(ip_connection, IP_LENGHT, 1, ip);
                                *port_connection = atoi(port);
                                return 0;   
                            } else {
                                waiting = false;
                            }
                        } else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                            if (line == 0)
                                str_remove_last_char(ip);
                            else if (line == 1)
                                str_remove_last_char(port);
                            waiting = false;
                        } else if (event.key.keysym.sym == SDLK_TAB) {
                            if (line == 1)
                                line = 0;
                            else
                                line++;
                                waiting = false;
                        }
                        break;
                }
            }
        }
        count++;
    }
    return 0;
}
