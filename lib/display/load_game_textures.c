/*
    Charge les textures pour afficher la carte et les personnages
*/
void load_game_textures(textures *textures, SDL_Renderer *renderer)
{
    (*textures).sprites = IMG_LoadTexture(renderer, PATH_PLAYER_TEXTURE);
    (*textures).background = IMG_LoadTexture(renderer, PATH_BACKGROUND_TEXTURE);
    (*textures).wall = IMG_LoadTexture(renderer, PATH_WALL_TEXTURE);
    (*textures).bloc = IMG_LoadTexture(renderer, PATH_BLOC_TEXTURE);
    (*textures).bomb = IMG_LoadTexture(renderer, PATH_BOMB_TEXTURE);
    (*textures).explosion = IMG_LoadTexture(renderer, PATH_EXPLOSION_TEXTURE);
}
