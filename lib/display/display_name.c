/*
    Affiche une interface pour que l'utilisateur puisse saisir dynamiquement son nom d'utilisateur
*/
void display_name(display *display, char *name)
{
    bool waiting = true;
    bool clear_screen = true;
    SDL_Event event;

    memset (name, 0, sizeof (name));
    while (clear_screen) { 
        SDL_SetRenderDrawColor(display->renderer, 0, 200, 50, 1);
        SDL_RenderClear(display->renderer);

        SDL_Rect rectangle = {110, 230, 290, 30};
        draw_rect(display, rectangle);

        display_text(display->renderer, GAME_NAME, 40, -1, 50, PATH_FONT_BOLD);
        display_text(display->renderer, TEXT_INTRO_NAME, 20, -1, 200, PATH_FONT);
        display_text(display->renderer, name, 20, -1, 230, PATH_FONT);
        display_text(display->renderer, TEXT_KEY_ENTER, 20, -1, 400, PATH_FONT);

        SDL_RenderPresent(display->renderer);

        waiting = true;

        while (waiting) {
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        exit(0);
                        break;
                    case SDL_TEXTINPUT:
                        add_new_char_to_str(name, NAME_LENGHT, 1, event.text.text);
                        waiting = false;
                        break;
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_ESCAPE) {
                            exit(0);
                        } else if (event.key.keysym.sym == SDLK_KP_ENTER || event.key.keysym.sym == SDLK_RETURN) {
                            waiting = false;
                            clear_screen = false;
                        } else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                            str_remove_last_char(name);
                            waiting = false;
                        }
                        break;
                }
            }
        }
    }
}
