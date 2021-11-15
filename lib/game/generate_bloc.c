/*
    Génère un bloc en fonction d'une probabilité donnée pour chacun des type de bloc
*/
int generate_bloc(int background, int prob_background, int bloc, int prob_bloc, int wall, int prob_wall, int bomb, int prob_bomb)
{
    int prob = rand() % 101;

    if (prob <= prob_background)
        return background;
    else if (prob <= prob_background + prob_bloc)
        return bloc;
    else if (prob <= prob_background + prob_bloc + prob_wall)
        return wall;
    else
        return bomb;
}
