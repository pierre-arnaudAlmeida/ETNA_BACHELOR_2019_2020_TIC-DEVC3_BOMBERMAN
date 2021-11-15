/*
    Vérifie que le nombre de joueurs vivant est suppérieur à 1
*/
int check_player_alive(game *game)
{
    int count = 0;
    int  time = SDL_GetTicks();
    
    if ((time - game->start_tick) >= game->game_time)
        return 1;
    for (int i = 0; i < MAX_PLAYERS; i++)
        if (game->player_list[i].player_id != 0 && game->player_list[i].is_alive >= 1)
            count++;

    if (count <= 1)
        return 1;
    else
        return 0;
}
