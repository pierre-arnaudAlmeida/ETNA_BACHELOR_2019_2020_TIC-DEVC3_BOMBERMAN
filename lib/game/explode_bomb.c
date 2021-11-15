/*
    Détruit toutes les bombes qui ont atteint le temps limite avant explosion, met les cases qui se trouvent
    autour en flammes
    Verifie si les 2 cases adjacentes à la bombe peuvent être exploser
*/
int destroy(game *game, int dir, location loc, int ite)
{
    int count = 0;

    if (ite == 1)
        for (int i = 0; i < MAX_PLAYERS; i++)
            if (game->player_list[i].player_id != 0 && ((game->player_list[i].location.x + (BLOC_SIZE / 2)) / BLOC_SIZE) == (loc.x / BLOC_SIZE) && ((game->player_list[i].location.y + (BLOC_SIZE / 2)) / BLOC_SIZE) == (loc.y / BLOC_SIZE)) {
                game->player_list[i].is_alive--;
                count++;
            }

    switch(dir) {
        case 1 :
            loc.y = loc.y + BLOC_SIZE;
            break;
        case 2 :
            loc.y = loc.y - BLOC_SIZE;
            break;
        case 3 :
            loc.x = loc.x - BLOC_SIZE;
            break;
        case 4 :
            loc.x = loc.x + BLOC_SIZE;
            break;
    }
    
    for (int i = 0; i < MAX_PLAYERS; i++)
        if (game->player_list[i].player_id != 0 && ((game->player_list[i].location.x + (BLOC_SIZE / 2)) / BLOC_SIZE) == (loc.x / BLOC_SIZE) && ((game->player_list[i].location.y + (BLOC_SIZE / 2)) / BLOC_SIZE) == (loc.y / BLOC_SIZE)) {
            game->player_list[i].is_alive--;
            count++;
        }

    if (game->game_map[loc.x / BLOC_SIZE][loc.y / BLOC_SIZE] == 0 && ite <= 2) {
            game->game_map[loc.x / BLOC_SIZE][loc.y / BLOC_SIZE] = 4;
            if (ite < 2)
                if (destroy(game, dir, loc, ++ite) == 1)
                    count++;
            count++;
    } else if (game->game_map[loc.x / BLOC_SIZE][loc.y / BLOC_SIZE] == 2) {
        game->game_map[loc.x / BLOC_SIZE][loc.y / BLOC_SIZE] = 4;
        count++;
    } else if (game->game_map[loc.x / BLOC_SIZE][loc.y / BLOC_SIZE] == 3) {
        for (int i = 0; i < MAX_PLAYERS; i++)
            if (game->player_list[i].player_id != 0)
                if (game->player_list[i].bomb.bomb_state == 1 &&
                    game->player_list[i].bomb.bomb_location.x == loc.x &&
                    game->player_list[i].bomb.bomb_location.y == loc.y) {
                    game->player_list[i].bomb.bomb_state = 2;
                    game->player_list[i].bomb.tick = SDL_GetTicks();
                    }
        destroy(game, 1, loc, 1);
        destroy(game, 2, loc, 1);
        destroy(game, 3, loc, 1);
        destroy(game, 4, loc, 1);
        game->game_map[loc.x / BLOC_SIZE][loc.y / BLOC_SIZE] = 4;
        count++;
    }

    if (count >= 1)
        return 1;
    else
        return 0;
}

/*
    Supprime les flammes après un temps imparti
*/
int remove_fire(game *game, int dir, location loc, int ite)
{
    int count = 0;

    switch(dir) {
        case 1 :
            loc.y = loc.y + BLOC_SIZE;
            break;
        case 2 :
            loc.y = loc.y - BLOC_SIZE;
            break;
        case 3 :
            loc.x = loc.x - BLOC_SIZE;
            break;
        case 4 :
            loc.x = loc.x + BLOC_SIZE;
            break;
    }
    
    if (game->game_map[loc.x / BLOC_SIZE][loc.y / BLOC_SIZE] == 4 && ite < 2) {
            game->game_map[loc.x / BLOC_SIZE][loc.y / BLOC_SIZE] = 0;
            if (remove_fire(game, dir, loc, ++ite) == 1)
                count++;
    } else if (game->game_map[loc.x / BLOC_SIZE][loc.y / BLOC_SIZE] == 4) {
        game->game_map[loc.x / BLOC_SIZE][loc.y / BLOC_SIZE] = 0;
        count++;
    }

    if (count >= 1)
        return 1;
    else
        return 0;
}

/*
    Explose les bombes qui sont active et dont le temps entre la pose et l'explosion est révolu
    Fait exploser les bombes qui se trouvent dans le champs d'action d'une bombe qui explose
*/
int explode_bomb(game *game)
{
    int count = 0;
    location loc;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (game->player_list[i].player_id != 0) {
            if (game->player_list[i].bomb.bomb_state == 1 && (SDL_GetTicks() - game->player_list[i].bomb.tick) >= EXPLOSION_LAPS) {
                loc.x = game->player_list[i].bomb.bomb_location.x;
                loc.y = game->player_list[i].bomb.bomb_location.y;
                game->game_map[loc.x / BLOC_SIZE][loc.y / BLOC_SIZE] = 4;
                if (destroy(game, 1, loc, 1) == 1)
                    count++;
                if (destroy(game, 2, loc, 1) == 1)
                    count++;
                if (destroy(game, 3, loc, 1) == 1)
                    count++;
                if (destroy(game, 4, loc, 1) == 1)
                    count++;
                game->player_list[i].bomb.bomb_state = 2;
                game->player_list[i].bomb.tick = SDL_GetTicks();
                count++;
            }
            
            if (game->player_list[i].bomb.bomb_state == 2) {
                loc.x = game->player_list[i].bomb.bomb_location.x;
                loc.y = game->player_list[i].bomb.bomb_location.y;
                if ((SDL_GetTicks() - game->player_list[i].bomb.tick) >= (EXPLOSION_LAPS / 4)) {
                    game->game_map[game->player_list[i].bomb.bomb_location.x / BLOC_SIZE][game->player_list[i].bomb.bomb_location.y / BLOC_SIZE] = 0;
                    if (remove_fire(game, 1, loc, 1) == 1)
                        count++;
                    if (remove_fire(game, 2, loc, 1) == 1)
                        count++;
                    if (remove_fire(game, 3, loc, 1) == 1)
                        count++;
                    if (remove_fire(game, 4, loc, 1) == 1)
                        count++;
                    game->player_list[i].bomb.bomb_state = 0;
                    game->player_list[i].bomb.tick = SDL_GetTicks();
                    count++;
                }
            }
        }
    }

    if (count >= 1)
        return 1;
    else
        return 0;
}
