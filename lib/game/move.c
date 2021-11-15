/*
    Modifie la position du personnage en fonction de la direction choisi par l'utilisateur
    On vérifie aussi si la case dans laquelle la personne souhaite etre déplacer est accéssible
*/
void move(game *game, direction direction, player *player)
{
    location location;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (game->player_list[i].player_id == player->player_id && game->player_list[i].player_id != 0) {
            game->player_list[i].mouvement = 1;
            location.x = game->player_list[i].location.x;
            location.y = game->player_list[i].location.y;
            switch (direction) {
                case UP:
                    location.y = location.y - BLOC_SIZE / 8;
                    if (check_move(game, location, direction, player) == 1)
                        game->player_list[i].location = location;
                    else
                        game->player_list[i].mouvement = 0;
                    break;
                case DOWN:
                    location.y = location.y + BLOC_SIZE / 8;
                    if (check_move(game, location, direction, player) == 1)
                        game->player_list[i].location = location;
                    else
                        game->player_list[i].mouvement = 0;
                    break;
                case LEFT:
                    location.x = location.x - BLOC_SIZE / 8;
                    if (check_move(game, location, direction, player) == 1)
                        game->player_list[i].location = location;
                    else
                        game->player_list[i].mouvement = 0;
                    break;
                case RIGHT:
                    location.x = location.x + BLOC_SIZE / 8;
                    if (check_move(game, location, direction, player) == 1)
                        game->player_list[i].location = location;
                    else
                        game->player_list[i].mouvement = 0;
                    break;
            }
            game->player_list[i].direction = direction; 
        }
    }
}
