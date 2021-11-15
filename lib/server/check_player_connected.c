/*
    Vérifie le nombre de clients connectés, si il n'y en a pas assez il ne commencera pas la partie
*/
int check_player_connected(game game)
{
    int count = 0;
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (game.player_list[i].player_id != 0)
            count++;    
    }
    
    if (count >= MIN_PLAYERS)
        return 0;
    else
        return 1;
}
