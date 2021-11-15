/*
    Affiche dans la fenêtre les différentes textures en fonction de l'état de la case
    Si la case est un mur, un bloc destructible, un espace vide, s'il y a une bombe, si ce sont des flammes ou s'il y a un joueur dessus
*/
void display_map(display *display, game *game)
{
    int h = 0;
    int w = 0;
    SDL_Rect texr;
    location texture_position;

    SDL_RenderClear(display->renderer);
    for (int i = 0; i < BLOC_WIDTH; i++) {
        texture_position.x = i * BLOC_SIZE;
        for (int j = 0; j < BLOC_HEIGHT; j++) {
            texture_position.y = j * BLOC_SIZE;
            texr.x = texture_position.x;
            texr.y = texture_position.y;
            switch (game->game_map[i][j]) {
                case 0 :
                    SDL_QueryTexture(display->textures.background, NULL, NULL, &w, &h);
                    texr.w = w;
                    texr.h = h;
                    SDL_RenderCopy(display->renderer, display->textures.background, NULL, &texr);
                    break;
                case 1 :
                    SDL_QueryTexture(display->textures.wall, NULL, NULL, &w, &h);
                    texr.w = w;
                    texr.h = h;
                    SDL_RenderCopy(display->renderer, display->textures.wall, NULL, &texr);
                    break;
                case 2 :
                    SDL_QueryTexture(display->textures.bloc, NULL, NULL, &w, &h);
                    texr.w = w;
                    texr.h = h;
                    SDL_RenderCopy(display->renderer, display->textures.bloc, NULL, &texr);
                    break;
                case 3 :
                    SDL_QueryTexture(display->textures.background, NULL, NULL, &w, &h);
                    texr.w = w;
                    texr.h = h;
                    SDL_RenderCopy(display->renderer, display->textures.background, NULL, &texr);

                    SDL_QueryTexture(display->textures.bomb, NULL, NULL, &w, &h);
                    texr.x = texture_position.x+2;
                    texr.y = texture_position.y+2;
                    texr.w = w;
                    texr.h = h;
                    SDL_RenderCopy(display->renderer, display->textures.bomb, NULL, &texr);
                    break;
                case 4 :
                    SDL_QueryTexture(display->textures.background, NULL, NULL, &w, &h);
                    texr.w = w;
                    texr.h = h;
                    SDL_RenderCopy(display->renderer, display->textures.background, NULL, &texr);

                    SDL_QueryTexture(display->textures.explosion, NULL, NULL, &w, &h);
                    texr.x = texture_position.x+2;
                    texr.y = texture_position.y+2;
                    texr.w = w;
                    texr.h = h;
                    SDL_RenderCopy(display->renderer, display->textures.explosion, NULL, &texr);
                    break;
            }
        }
    }
    display_player(game, display, texr);
    
    SDL_RenderPresent(display->renderer);
}
