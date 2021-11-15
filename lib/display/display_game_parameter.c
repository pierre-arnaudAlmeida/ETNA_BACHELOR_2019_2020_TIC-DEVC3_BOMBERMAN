/*
    Affiche le choix des parametre pour la partie
    Permet de choisir le nombre de vie qu'aurons les personnages
    Permet de choisir le temps que peut durer maximum la partie avant sont arret
*/
int display_game_parameter(display *display, game *game)
{
    bool waiting = true;
    bool clear_screen = true;
    SDL_Event event;
    char str[STR_MAX_SIZE];
    game->life = 1;
    int time = 1;
    int line = 0;

    while (clear_screen) { 
        SDL_SetRenderDrawColor(display->renderer, 0, 200, 50, 1);
        SDL_RenderClear(display->renderer);

        SDL_Rect rectangle = {180, (175 + (line * 60)), 150, 30};
        draw_rect(display, rectangle);

        display_text(display->renderer, TEXT_CREATE_GAME, 40, -1, 50, PATH_FONT_BOLD);
        display_text(display->renderer, TEXT_LIFE, 15, -1, 150, PATH_FONT);
        memset (str, 0, sizeof (str));
        to_string(str, game->life);
        display_text(display->renderer, str, 15, -1, 180, PATH_FONT);

        display_text(display->renderer, TEXT_TIME, 15, -1, 210, PATH_FONT);
        memset (str, 0, sizeof (str));
        to_string(str, time);
        strcat(str, " Min");
        display_text(display->renderer, str, 15, -1, 240    , PATH_FONT);

        display_text(display->renderer, TEXT_KEY_PLUS, 15, -1, 340, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_MINUS, 15, -1, 360, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_CONTINUE, 15, -1, 380, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_BACK, 15, -1, 400, PATH_FONT);

        SDL_RenderPresent(display->renderer);
    
        waiting = true;

        while (waiting) {
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        return 1;
                        break;
                    case SDL_KEYDOWN:
                        waiting = false;
                        if (event.key.keysym.sym == SDLK_ESCAPE) {
                            return 1;
                        } else if (event.key.keysym.sym == SDLK_RIGHT) {
                            if (line == 0)
                                game->life++;
                            else if (line == 1)
                                time++;
                        } else if (event.key.keysym.sym == SDLK_LEFT) {
                            if (line == 0) {
                                if (game->life > 1)
                                    game->life--;
                            } else if (line == 1) {
                                if (time > 1)
                                    time--;
                            }
                        } else if (event.key.keysym.sym == SDLK_KP_ENTER || event.key.keysym.sym == SDLK_RETURN) {
                            clear_screen = false;
                        } else if (event.key.keysym.sym == SDLK_TAB) {
                            if (line == 1)
                                line = 0;
                            else
                                line++;
                        }
                        break;
                }
            }
        }
    }
    game->game_time = time * 60000;
    return 0;
}
