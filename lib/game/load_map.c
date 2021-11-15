/*
    On charge une carte déjà créer par un joueurs ou par les développeur du jeu.
    Les cartes se trouvent dans le dossier maps
*/
void load_map(game *game, char lvl_path[])
{
    FILE *file = NULL;
    char *str = (char *) malloc(15);
    char *element = (char *) malloc(1);
    int j = 0;

    file = fopen(lvl_path, "r");
 
    if (file != NULL) {
        j = 0;
        while (fgets(str, 17, file) != NULL) {   
            for (int i = 0; i < strlen(str) - 1; i++) {
                *element = str[i];
                game->game_map[i][j] = atoi(element);
            }
            j++;
        }

        free(str) ;
        free(element);
        fclose(file);
    }
}
