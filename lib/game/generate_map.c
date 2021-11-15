/*
    Génère une carte aléatoire
    Case vide = 0
    Case avec un mur = 1
    Case avec un bloc = 2
    Case avec une bombe = 3
*/
void generate_map(game *game)
{
    for (int i = 0; i < BLOC_HEIGHT; i++) {
        for (int j = 0; j < BLOC_WIDTH; j++) {
            if (i == 0)
                game->game_map[i][j] = 1;
            else if (i == BLOC_HEIGHT - 1)
                game->game_map[i][j] = 1;
            else if (j == 0 || j == BLOC_WIDTH - 1)
                game->game_map[i][j] = 1;
            else if (i % 2 == 0 && j % 2 == 0)
                game->game_map[i][j] = 1;
            else if ((j>2 && j<12) || (i>2 && i<12))
                game->game_map[i][j] = generate_bloc(0, 45, 2, 55, 1, 0, 3, 0);
            else 
                game->game_map[i][j] = 0;
        }
    }
}
