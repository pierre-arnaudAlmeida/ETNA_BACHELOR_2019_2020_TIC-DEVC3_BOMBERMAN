/*
    Affiche un rectangle de couleur noir
*/
void draw_rect (display *display, SDL_Rect rectangle)
{
    SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 0);

    for (int y = rectangle.y; y < rectangle.y + rectangle.h; y++)
        for (int x = rectangle.x; x < rectangle.x + rectangle.w; x++)
            SDL_RenderDrawPoint(display->renderer, x, y);
}
