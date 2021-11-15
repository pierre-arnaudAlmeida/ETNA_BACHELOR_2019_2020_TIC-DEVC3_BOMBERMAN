#ifndef __MY_H_H__
#define __MY_H_H__

#include <unistd.h>
#include "structures.h"
#include "../lib/other/to_string.c"
#include "../lib/other/str_remove_last_char.c"
#include "../lib/other/add_new_char_to_str.c"
#include "../lib/other/is_int.c"
#include "../lib/other/get_ip.c"
#include "../lib/other/to_str_player_address.c"
#include "../lib/other/search_iteration.c"
#include "../lib/game/generate_bloc.c"
#include "../lib/game/generate_map.c"
#include "../lib/game/load_map.c"
#include "../lib/display/load_game_textures.c"
#include "../lib/display/init_display.c"
#include "../lib/display/display_text.c"
#include "../lib/display/display_menu.c"
#include "../lib/display/display_winner.c"
#include "../lib/display/display_players.c"
#include "../lib/display/display_map.c"
#include "../lib/game/init_players.c"
#include "../lib/game/check_move.c"
#include "../lib/game/put_bomb.c"
#include "../lib/game/move.c"
#include "../lib/display/draw_rect.c"
#include "../lib/display/display_name.c"
#include "../lib/server/check_sock.c"
#include "../lib/display/display_key_tips_server.c"
#include "../lib/game/check_ip_port.c"
#include "../lib/game/check_player_alive.c"
#include "../lib/client/client.c"
#include "../lib/display/display_key_tips_client.c"
#include "../lib/game/explode_bomb.c"
#include "../lib/game/get_mouvement.c"
#include "../lib/server/server.c"
#include "../lib/server/check_player_connected.c"
#include "../lib/display/display_connected_players.c"
#include "../lib/display/display_init_game_menu.c"
#include "../lib/display/display_join_game_menu.c"
#include "../lib/display/display_game_parameter.c"
#include "../lib/game/init_game.c"

#endif

void to_string(char text[], int nb);
char* str_remove_last_char(char* text);
void add_new_char_to_str (char *text, int lenght, int count, char *new_text);
bool is_int(char *nb);
void get_ip(char *ip);
void to_str_player_address(char text[] ,struct sockaddr_in addr);
int search_iteration(char *str, char c);
int generate_bloc(int val1, int probaVal1, int val2, int probaVal2, int val3, int probaVal3, int val4, int probaVal4);
void generate_map(game *game);
void load_map(game *game, char lvl_path[]);
void load_game_textures(textures *textures, SDL_Renderer *renderer);
void init_display(display *display);
void display_text(SDL_Renderer *renderer, char text[], int text_size, int location_x, int location_y, char font_path[]);
void display_menu(display *display);
void display_winner(display *display, game * game);
void display_players(game *game, display *display, SDL_Rect texr);
void display_map(display *display, game *game);
void init_players(game *game);
int check_move(game *game, location location, direction direction, player *player);
void put_bomb(game *game, player *player);
void move(game *game, direction direction, player *player);
void set_direction(int new_direction);
void get_mouvement(game *game, player *player);
void draw_rect (display *display, SDL_Rect rectangle);
void display_name(display *display, char *name);
int check_sock(server *server_data);
int display_key_tips_server(display *display, server *server_data);
int check_ip_port(char *ip, char *port, char *message);
int check_player_alive(game *game);
void send_start_msg();
server* get_server_data();
void set_server_data();
server* get_client_data();
void set_client_data();
int display_key_tips_client(display *display, server *server_data);
int explode_bomb(game *game);
void init_game(display *display, game *game, player *player);
void *handle_main_client(void *arg);
void *handle_main_serveur(void *arg);
int check_player_connected(game game);
int display_connected_players(display *display, server *server_data);
int display_init_game_menu(display *display, game *game);
int display_join_game_menu(display *display, char *ip_connection, int *port_connection);
int display_game_parameter(display *display, game *game);
