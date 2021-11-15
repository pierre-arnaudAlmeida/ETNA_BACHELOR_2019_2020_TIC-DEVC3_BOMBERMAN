/*
    Pose une bombe sur la carte
    Si la case où le joueur souhaite poser la bombe est disponible
    On initialise donc la bombe à 1
*/
void put_bomb(game *game, player *player)
{
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (game->player_list[i].player_id == player->player_id && game->player_list[i].player_id != 0){
            if (game->player_list[i].bomb.bomb_state == 0) {
                game->game_map[(game->player_list[i].location.x + (BLOC_SIZE / 2)) / BLOC_SIZE][(game->player_list[i].location.y + (BLOC_SIZE / 2)) / BLOC_SIZE] = 3;
                game->player_list[i].bomb.bomb_location.x = (game->player_list[i].location.x + (BLOC_SIZE / 2));
                game->player_list[i].bomb.bomb_location.y = (game->player_list[i].location.y + (BLOC_SIZE / 2));
                game->player_list[i].bomb.bomb_state = 1;
                game->player_list[i].bomb.tick = SDL_GetTicks();
            }
        }
    }
}
