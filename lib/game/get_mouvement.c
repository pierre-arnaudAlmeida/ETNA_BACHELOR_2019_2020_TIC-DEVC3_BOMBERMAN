/*
    Récupère les mouvements que souhaite éffectué le joueur
*/
void get_mouvement(game *game, player *player)
{
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (game->player_list[i].player_id == player->player_id && game->player_list[i].player_id != 0) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        game->game_state = 0;
                        break;
                    case SDL_KEYDOWN:
                        if ((event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_z) && game->player_list[i].is_alive >= 1)
                            set_direction(1);
                        else if ((event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) && game->player_list[i].is_alive >= 1)
                            set_direction(2);
                        else if ((event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_q) && game->player_list[i].is_alive >= 1)
                            set_direction(3);
                        else if ((event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d) && game->player_list[i].is_alive >= 1)
                            set_direction(4);
                        else if ((event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_b) && game->player_list[i].is_alive >= 1)
                            set_direction(5);
                        else if (event.key.keysym.sym == SDLK_ESCAPE)
                            set_direction(99);
                        break;
                }
            }
        }
    }
}
