/*
    Affiche un menu au créateur de la partie pour lui permettre
    de choisir une carte parmis les cartes disponnibles ou 
    de générer une carte aléatoire
*/
int display_init_game_menu(display *display, game *game)
{
    bool waiting = true;
    SDL_Event event;

    SDL_SetRenderDrawColor(display->renderer, 0, 200, 50, 1);
    SDL_RenderClear(display->renderer);

    display_text(display->renderer, TEXT_CREATE_GAME, 40, -1, 50, PATH_FONT_BOLD);

    display_text(display->renderer, TEXT_SELECT_MAP_PART_1, 15, -1, 100, PATH_FONT);
    display_text(display->renderer, TEXT_SELECT_MAP_PART_2, 15, -1, 120, PATH_FONT);

    display_text(display->renderer, TEXT_LVL_1, 15, -1, 150, PATH_FONT);
    display_text(display->renderer, TEXT_LVL_2, 15, -1, 170, PATH_FONT);
    display_text(display->renderer, TEXT_LVL_3, 15, -1, 190, PATH_FONT);
    display_text(display->renderer, TEXT_LVL_4, 15, -1, 210, PATH_FONT);
    display_text(display->renderer, TEXT_LVL_5, 15, -1, 230, PATH_FONT);
    display_text(display->renderer, TEXT_LVL_6, 15, -1, 250, PATH_FONT);
    display_text(display->renderer, TEXT_LVL_7, 15, -1, 270, PATH_FONT);
    display_text(display->renderer, TEXT_LVL_PERSO_1, 15, -1, 290, PATH_FONT);
    display_text(display->renderer, TEXT_LVL_PERSO_2, 15, -1, 310, PATH_FONT);
    display_text(display->renderer, TEXT_LVL_PERSO_3, 15, -1, 330, PATH_FONT);
    display_text(display->renderer, TEXT_RANDOM_LVL, 15, -1, 350, PATH_FONT);
    display_text(display->renderer, TEXT_KEY_BACK, 15, -1, 400, PATH_FONT);

    SDL_RenderPresent(display->renderer);
    
    while (waiting) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    waiting = false;
                    return 1;
                    break;
                case SDL_KEYDOWN:
                    waiting = false;
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        return 1;
                    else if (event.key.keysym.sym == SDLK_0 || event.key.keysym.sym == SDLK_KP_0)
                        load_map(game, PATH_LVL_1);
                    else if (event.key.keysym.sym == SDLK_1 || event.key.keysym.sym == SDLK_KP_1)
                        load_map(game, PATH_LVL_2);
                    else if (event.key.keysym.sym == SDLK_2 || event.key.keysym.sym == SDLK_KP_2)
                        load_map(game, PATH_LVL_3);
                    else if (event.key.keysym.sym == SDLK_3 || event.key.keysym.sym == SDLK_KP_3)
                        load_map(game, PATH_LVL_4);
                    else if (event.key.keysym.sym == SDLK_4 || event.key.keysym.sym == SDLK_KP_4)
                        load_map(game, PATH_LVL_5);
                    else if (event.key.keysym.sym == SDLK_5 || event.key.keysym.sym == SDLK_KP_5)
                        load_map(game, PATH_LVL_6);
                    else if (event.key.keysym.sym == SDLK_6 || event.key.keysym.sym == SDLK_KP_6)
                        load_map(game, PATH_LVL_7);
                    else if (event.key.keysym.sym == SDLK_7 || event.key.keysym.sym == SDLK_KP_7)
                        load_map(game, PATH_LVL_PERSO_1);
                    else if (event.key.keysym.sym == SDLK_8 || event.key.keysym.sym == SDLK_KP_8)
                        load_map(game, PATH_LVL_PERSO_2);
                    else if (event.key.keysym.sym == SDLK_9 || event.key.keysym.sym == SDLK_KP_9)
                        load_map(game, PATH_LVL_PERSO_3);
                    else if (event.key.keysym.sym == SDLK_r)
                        generate_map(game);
                    else
                        waiting = true;
                    break;
            }
        }
    }
    return 0;
}
