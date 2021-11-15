/*
    Affiche le gagnant de la partie
    S'il n'y a qu'un seul joueur en vie, alors il est désigner gagnant
    Mais s'il y  a plusieurs joueurs c'est un match nul
*/
void display_winner(display *display, game * game)
{
    bool waiting = true;
    SDL_Event event;
    char winner[NAME_LENGHT] = "";
    int count = 0;

    SDL_SetRenderDrawColor(display->renderer, 0, 200, 50, 1);
    SDL_RenderClear(display->renderer);

    display_text(display->renderer, TEXT_WINNER, 40, -1, 100, PATH_FONT_BOLD);
    for (int i = 0; i < MAX_PLAYERS; i++)
        if (game->player_list[i].player_id != 0 && game->player_list[i].is_alive >= 1) {
            count++;
            strcat(winner, game->player_list[i].name);
        }
    if (count == 1)
        display_text(display->renderer, winner, 30, -1, 200, PATH_FONT_BOLD);
    else
        display_text(display->renderer, TEXT_NULL_GAME, 30, -1, 200, PATH_FONT_BOLD);
    SDL_RenderPresent(display->renderer);
    
    while (waiting) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    waiting = false;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_KP_ENTER || event.key.keysym.sym == SDLK_RETURN)
                        waiting = false;
                    break;
            }
        }
    }
}
