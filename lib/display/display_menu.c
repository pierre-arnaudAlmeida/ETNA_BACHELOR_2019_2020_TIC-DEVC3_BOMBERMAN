/*
    Affiche le menu du jeu
    Permet de créer une partie ou de rejoindre
    une partie déja existante
    mais aussi un menu d'edition des cartes qui n'est pas encore disponible
*/
void display_menu(display *display)
{
    SDL_SetRenderDrawColor(display->renderer, 0, 200, 50, 1);
    SDL_RenderClear(display->renderer);

    display_text(display->renderer, GAME_NAME, 40, -1, 100, PATH_FONT_BOLD);

    display_text(display->renderer, TEXT_INTRO_PART_1, 20, -1, 200, PATH_FONT);
    display_text(display->renderer, TEXT_INTRO_PART_2, 20, -1, 225, PATH_FONT);
    display_text(display->renderer, TEXT_KEY_1_MENU, 20, -1, 270, PATH_FONT);
    display_text(display->renderer, TEXT_KEY_2_MENU, 20, -1, 295, PATH_FONT);
    display_text(display->renderer, TEXT_KEY_3_MENU, 20, -1, 320, PATH_FONT);
    display_text(display->renderer, TEXT_KEY_QUIT, 20, -1, 345, PATH_FONT);

    SDL_RenderPresent(display->renderer);
}
