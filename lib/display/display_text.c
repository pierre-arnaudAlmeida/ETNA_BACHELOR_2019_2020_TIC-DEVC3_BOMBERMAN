/*
    Affiche un texte sur l'écran a une position définit, une taille
    et une police d'écriture en blanc
*/
void display_text(SDL_Renderer *renderer, char text[], int text_size, int location_x, int location_y, char font_path[])
{
    int w;
    int h;
    SDL_Color text_color = {.r = 255, .g = 255, .b = 255};

    TTF_Font *font = TTF_OpenFont(font_path, text_size);
    SDL_Surface *surface = TTF_RenderText_Blended(font, text, text_color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_QueryTexture(texture, NULL, NULL, &w, &h);

    if (location_x == -1)
        location_x = (WINDOW_WIDTH / 2) - (w / 2);
    if (location_y == -1)
        location_y = (WINDOW_HEIGHT / 2) - (h / 2);
    SDL_Rect texr = {location_x, location_y, w, h};

    SDL_RenderCopy(renderer, texture, NULL, &texr);

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    SDL_DestroyTexture(texture);
}
