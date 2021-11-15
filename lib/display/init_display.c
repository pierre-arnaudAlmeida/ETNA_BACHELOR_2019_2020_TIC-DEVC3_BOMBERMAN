/*
    Crée la fenêtre et l'affiche a l'écran en fonction des différentes constantes présente dasn le fichier constantes.h
*/
void init_display(display *display)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        SDL_Quit();
    }
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    
    display->window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (NULL == display->window) {
        fprintf(stderr, "Erreur à la création de la fenêtre : %s", SDL_GetError());
        SDL_Quit();
    }
    SDL_RaiseWindow(display->window);

    display->renderer = SDL_CreateRenderer(display->window, -1, SDL_RENDERER_ACCELERATED);
    load_game_textures(&display->textures, display->renderer);
}
