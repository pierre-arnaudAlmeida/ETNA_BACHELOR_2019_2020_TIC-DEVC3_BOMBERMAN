/*
    Affiche les joueurs aux quatres coin de la carte
*/
void display_player(game *game, display *display, SDL_Rect texr)
{
    SDL_Rect split_sprite;
    SDL_Rect init_sprite = {15, 13, 35, 50};
    int frame;
    int nb_frames = 9;
    int delay_per_frame = 90;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (game->player_list[i].is_alive >= 1 && game->player_list[i].player_id != 0) {
            split_sprite = init_sprite;

            if(game->player_list[i].mouvement == 1)
                frame = (SDL_GetTicks() / delay_per_frame) % nb_frames;
            else
                frame = 0;
            split_sprite.x += frame * 64;
            
            if (game->player_list[i].direction == UP)
                split_sprite.y += 0;
            if (game->player_list[i].direction == LEFT)
                split_sprite.y += 64;
            if (game->player_list[i].direction == DOWN)
                split_sprite.y += 2*64;
            if (game->player_list[i].direction == RIGHT)
                split_sprite.y += 3*64;

            switch (i) {
                case 0:
                    SDL_SetTextureColorMod(display->textures.sprites, 255, 255, 255);
                    break;
                case 1:
                    SDL_SetTextureColorMod(display->textures.sprites, 0, 100, 255);
                    break;
                case 2:
                    SDL_SetTextureColorMod(display->textures.sprites, 0, 255, 100);
                    break;
                case 3:
                    SDL_SetTextureColorMod(display->textures.sprites, 255, 70, 0);
                    break;
            }
            texr.x = game->player_list[i].location.x;
            texr.y = game->player_list[i].location.y;
            SDL_RenderCopy(display->renderer, display->textures.sprites, &split_sprite, &texr);
        }
        game->player_list[i].mouvement = 0;
    }
}
