#include <stdio.h>
#include "../include/my_h.h"

int main (int argc, char *argv[])
{
    bool waiting = true;
    game game;
    display display;
    player player;

    player.player_id = 0;

    init_display(&display, GAME_NAME);
    display_menu(&display);

    SDL_Event event;
    while (waiting) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    waiting = false;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_1 || event.key.keysym.sym == SDLK_KP_1) {
                        SDL_RenderClear(display.renderer);
                        if (display_init_game_menu(&display, &game) == 0)
                            if (display_key_tips(&display) == 0)
                                init_game(&display, &game, &player);
                    } else if (event.key.keysym.sym == SDLK_2 || event.key.keysym.sym == SDLK_KP_2) {
                        join_game();
                    } else if (event.key.keysym.sym == SDLK_ESCAPE) {
                        waiting = false;
                    }
                    break;
            }
        }
        display_menu(&display);
    }

    SDL_DestroyRenderer(display.renderer);
    SDL_DestroyWindow(display.window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
