/*
    Initialise les joueurs de la partie
    Chaque joueurs aura le nombre de vie définit au début par le propriétaire de la partie
    et en fonction du nombre de joueurs il seront positionner tout autour de la carte
*/
void init_players(game *game)
{
    game->nb_players = MAX_PLAYERS;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        game->player_list[i].is_alive = game->life;
        game->player_list[i].player_id = 0;
        
        switch(i) {
            case 0:
                game->player_list[i].location.x = 34;
                game->player_list[i].location.y = 34;
                break;
            case 1:
                game->player_list[i].location.x = WINDOW_WIDTH - (2 * 34);
                game->player_list[i].location.y = WINDOW_HEIGHT - (2 * 34);
                break;
            case 2:
                game->player_list[i].location.x = WINDOW_WIDTH - (2 * 34);
                game->player_list[i].location.y = 34;
                break;
            case 3:
                game->player_list[i].location.x = 34;
                game->player_list[i].location.y = WINDOW_HEIGHT - (2 * 34);
                break;
        }
        game->player_list[i].direction = DOWN;
        game->player_list[i].mouvement = 0;
        game->player_list[i].bomb.bomb_location.x = 0;
        game->player_list[i].bomb.bomb_location.y = 0;
        game->player_list[i].bomb.bomb_state = 0;
    }
}
