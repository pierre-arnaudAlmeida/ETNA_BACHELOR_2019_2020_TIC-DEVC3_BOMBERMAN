#ifndef _STRUCTS_
#define _STRUCTS_

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "constantes.h" 

#endif

typedef struct textures {
    SDL_Texture *sprites;
    SDL_Texture *background;
    SDL_Texture *wall;
    SDL_Texture *bloc;
    SDL_Texture *bomb;
    SDL_Texture *explosion;
} textures;

typedef struct display {
    SDL_Window *window;
    SDL_Renderer *renderer;
    textures textures;
} display;

typedef struct location {
    int x;
    int y;
} location;

typedef enum direction {
    UP, DOWN, LEFT, RIGHT
} direction;

typedef struct bomb {
    location bomb_location;
    int bomb_state;
    int tick;
} bomb;

typedef struct player {
    int sockfd;
	char name[NAME_LENGHT];
    int is_alive;
    location location;
    bomb bomb;
    direction direction;
    int mouvement;
    int player_id;
    struct sockaddr_in address;
} player;

typedef struct game {
    int game_map[BLOC_WIDTH][BLOC_HEIGHT];
    int nb_players;
    player player_list[MAX_PLAYERS];
    int game_state;
    int life;
    int start_tick;
    int game_time;
} game;

typedef struct server {
    char message[BUFFER_SIZE];
    char ip[IP_LENGHT + 1];
    int port;
    struct sockaddr_in serv_addr;
    int listenfd;
    int connfd;
    game game;
    player player;
} server;
