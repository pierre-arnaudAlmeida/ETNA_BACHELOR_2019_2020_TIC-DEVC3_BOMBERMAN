/*
    Vérifie si la position demander est accéssible
    Vérifie qu'il n'y a pas de joueurs de bombe, de murs, de blocs ou de flammes se trouvant sur
    la position que le joueur souhaite accéder
*/
int check_move(game *game, location location, direction direction, player *player)
{
    if (direction == UP || direction == DOWN) {
        if (location.x % BLOC_SIZE == 0) {
            if (game->game_map[location.x / BLOC_SIZE][location.y / BLOC_SIZE] != 0 && direction == UP) {
                if (game->game_map[location.x / BLOC_SIZE][location.y / BLOC_SIZE] == 3)
                    for (int i = 0; i < MAX_PLAYERS; i++)
                        if (game->player_list[i].player_id != 0)
                            if (game->player_list[i].player_id == player->player_id && 
                                ((location.x+(34/2)) / BLOC_SIZE) == ((game->player_list[i].location.x+(34/2)) / BLOC_SIZE) &&  
                                ((location.y+(34/2)) / BLOC_SIZE) == ((game->player_list[i].location.y+(34/2)) / BLOC_SIZE))
                                return 1;
                return 0;
            } else if (game->game_map[location.x / BLOC_SIZE][(location.y + BLOC_SIZE - BLOC_SIZE / 8) / BLOC_SIZE] != 0 && direction == DOWN) {
                if (game->game_map[location.x / BLOC_SIZE][(location.y + BLOC_SIZE - BLOC_SIZE / 8) / BLOC_SIZE] == 3)
                    for (int i = 0; i < MAX_PLAYERS; i++)
                        if (game->player_list[i].player_id != 0)
                            if (game->player_list[i].player_id == player->player_id && 
                                ((location.x+(34/2)) / BLOC_SIZE) == ((game->player_list[i].location.x+(34/2)) / BLOC_SIZE) &&  
                                ((location.y+(34/2)) / BLOC_SIZE) == ((game->player_list[i].location.y+(34/2)) / BLOC_SIZE))
                                return 1;
                return 0;
            } else {
                for (int i = 0; i < MAX_PLAYERS; i++)
                    if (game->player_list[i].player_id != 0) {
                        if (game->player_list[i].location.x == location.x && 
                            (game->player_list[i].location.y / BLOC_SIZE) == (location.y / BLOC_SIZE) && 
                            direction == UP && 
                            game->player_list[i].player_id != player->player_id)
                            return 0;
                        else if (game->player_list[i].location.x == location.x && 
                            (game->player_list[i].location.y / BLOC_SIZE) == ((location.y + BLOC_SIZE) / BLOC_SIZE) && 
                            direction == DOWN && 
                            game->player_list[i].player_id != player->player_id)
                            return 0;
                    }
                return 1;
            }
        }
    } else if (direction == RIGHT || direction == LEFT) {
        if (location.y % BLOC_SIZE == 0) {
            if (game->game_map[location.x / BLOC_SIZE][location.y / BLOC_SIZE] != 0 && direction == LEFT) {
                if (game->game_map[location.x / BLOC_SIZE][location.y / BLOC_SIZE] == 3)
                    for (int i = 0; i < MAX_PLAYERS; i++)
                        if (game->player_list[i].player_id != 0)
                            if (game->player_list[i].player_id == player->player_id && 
                                ((location.x+(34/2)) / BLOC_SIZE) == ((game->player_list[i].location.x+(34/2)) / BLOC_SIZE) &&  
                                ((location.y+(34/2)) / BLOC_SIZE) == ((game->player_list[i].location.y+(34/2)) / BLOC_SIZE))
                                return 1;
                return 0;
            } else if (game->game_map[(location.x + BLOC_SIZE - BLOC_SIZE / 8) / BLOC_SIZE][location.y / BLOC_SIZE] != 0 && direction == RIGHT) {
                if (game->game_map[(location.x + BLOC_SIZE - BLOC_SIZE / 8) / BLOC_SIZE][location.y / BLOC_SIZE] == 3)
                    for (int i = 0; i < MAX_PLAYERS; i++)
                        if (game->player_list[i].player_id != 0)
                            if (game->player_list[i].player_id == player->player_id && 
                                ((location.x+(34/2)) / BLOC_SIZE) == ((game->player_list[i].location.x+(34/2)) / BLOC_SIZE) &&  
                                ((location.y+(34/2)) / BLOC_SIZE) == ((game->player_list[i].location.y+(34/2)) / BLOC_SIZE))
                                return 1;
                return 0;
            } else {
                for (int i = 0; i < MAX_PLAYERS; i++)
                    if (game->player_list[i].player_id != 0) {
                        if ((game->player_list[i].location.x / BLOC_SIZE) == (location.x / BLOC_SIZE) && 
                            game->player_list[i].location.y == location.y && 
                            direction == LEFT && 
                            game->player_list[i].player_id != player->player_id)
                            return 0;
                        else if ((game->player_list[i].location.x / BLOC_SIZE) == ((location.x + BLOC_SIZE) / BLOC_SIZE) && 
                            game->player_list[i].location.y == location.y && 
                            direction == RIGHT && 
                            game->player_list[i].player_id != player->player_id)
                            return 0;
                    }
                return 1;
            }
        }
    }
}
