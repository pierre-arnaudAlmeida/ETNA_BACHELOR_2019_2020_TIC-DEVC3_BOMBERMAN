#include <stdio.h>
#include "../include/my_h.h"

int main(int argc, char *argv[])
{
    bool waiting = true;
    pthread_t serveur_thread;
    pthread_t client_thread;
    server server_data;
    game game;
    display display;
    player player;

    srand(time(0));
    player.player_id = rand() % 9999999 + 1;

    init_display(&display);
    display_name(&display, player.name);
    display_menu(&display);

    SDL_Event event;
    while (waiting) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    waiting = false;
                    break;
                case SDL_KEYDOWN:
                    server_data.game = game;
                    server_data.player = player;
                    server_data.game.game_state = 0;
                    if (event.key.keysym.sym == SDLK_1 || event.key.keysym.sym == SDLK_KP_1) {
                        SDL_RenderClear(display.renderer);
                        if (display_init_game_menu(&display, &server_data.game) == 0)
                            if (display_game_parameter(&display, &server_data.game) == 0) {
                                if (display_key_tips_server(&display, &server_data) == 0) {
                                    init_players(&server_data.game);
                                    pthread_create(&serveur_thread, NULL, handle_main_serveur, (void *)&server_data);
                                    pthread_create(&client_thread, NULL, handle_main_client, (void *)&server_data);
                                    sleep(1);
                                    if (display_connected_players(&display, &server_data) == 0) {
                                        init_game(&display, &server_data.game, &player);
                                        display_winner(&display, &server_data.game);
                                    }
                                }
                            }
                    } else if (event.key.keysym.sym == SDLK_2 || event.key.keysym.sym == SDLK_KP_2) {
                        memset (server_data.ip, 0, sizeof (server_data.ip));
                        if (display_join_game_menu(&display, server_data.ip, &server_data.port) == 0){
                            pthread_create(&client_thread, NULL, handle_main_client, (void *)&server_data);
                            sleep(1);
                            set_client_data(&server_data);
                            if (display_key_tips_client(&display, &server_data) == 0) {
                                init_game(&display, &server_data.game, &player);
                                display_winner(&display, &server_data.game);
                            }
                        }
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
