#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

#define GAME_NAME               "Bomberman"
#define BLOC_SIZE               34
#define BLOC_WIDTH              15
#define BLOC_HEIGHT             15
#define WINDOW_WIDTH            BLOC_SIZE*BLOC_WIDTH
#define WINDOW_HEIGHT           BLOC_SIZE*BLOC_HEIGHT
#define MAX_PLAYERS             4
#define MIN_PLAYERS             2
#define BUFFER_SIZE             2048
#define IP_LENGHT               15
#define PORT_LENGHT             5
#define STR_MAX_SIZE            255
#define DEFAULT_PORT            4444
#define DEFAULT_IP              "127.0.0.1"
#define GOOGLE_DNS_SVR          "8.8.8.8"
#define DNS_PORT                53
#define NAME_LENGHT             25
#define EXPLOSION_LAPS          4000

#define TEXT_SELECT_MAP_PART_1  "Taper un des numeros"
#define TEXT_SELECT_MAP_PART_2  "pour choisir une carte"
#define TEXT_KEY_1_MENU         "1.    Creer une partie"
#define TEXT_KEY_2_MENU         "2.    Rejoindre une partie"
#define TEXT_KEY_3_MENU         "3.    Editer une carte"
#define TEXT_KEY_QUIT           "ECHAP  =  Quitter"
#define TEXT_KEY_BACK           "ECHAP  =  Retour"
#define TEXT_KEY_ENTER          "Taper sur entrer pour commencer"
#define TEXT_CREATE_GAME        "Creer une partie"
#define TEXT_JOIN_GAME          "Rejoindre une partie"
#define TEXT_INTRO_PART_1       "Taper un des numeros"
#define TEXT_INTRO_PART_2       "pour passer a la suite"
#define TEXT_KEY_TIPS           "Astuces touches"
#define TEXT_KEY_UP             "Aller vers le haut = Fleche du haut ou Z"
#define TEXT_KEY_DOWN           "Aller vers le bas = Fleche du bas ou S"
#define TEXT_KEY_LEFT           "Aller vers la gauche = Fleche de gauche ou Q"
#define TEXT_KEY_RIGHT          "Aller vers la droite = Fleche de droite ou D"
#define TEXT_KEY_SPACE          "Poser la bombe = ESPACE"
#define TEXT_KEY_SURREND        "Abandonner = ECHAP"
#define TEXT_INTRO_IP           "Taper l'addresse ip de la partie :"
#define TEXT_INTRO_PORT         "Taper le port :"
#define TEXT_KEY_CONTINUE       "Taper sur entrer pour continuer"
#define TEXT_KEY_TAB            "Taper sur tab pour changer de champs"
#define IP_ERROR_FORMAT         "Ip invalide : un des 4 nombres n'est pas valide"
#define IP_ERROR_FORMAT_2       "Ip invalide : un des 4 nombres est superieur a 255"
#define IP_ERROR_FORMAT_3       "Ip invalide : Il n'y a pas 4 nombres distinct separer pas des point"
#define PORT_ERROR_FORMAT       "Port invalide : ce port n'est pas un nombre"
#define PORT_ERROR_USED         "Port utiliser par un autre processus"
#define TEXT_START              "Dans les starting blocks"
#define TEXT_JOIN_IP            "IP du serveur :"
#define TEXT_JOIN_PORT          "Port du serveur :"
#define TEXT_INTRO_NAME         "Taper votre nom de personnage :"
#define TEXT_CONECTED_PLAYER    "Joueurs Connectes :"
#define TEXT_WAIT_START         "Attender le debut de la partie"
#define TEXT_WINNER             "Le gagnant est :"
#define TEXT_KEY_PLUS           "Taper sur la fleche de droite pour +"
#define TEXT_KEY_MINUS          "Taper sur la fleche de gaiche pour -"
#define TEXT_LIFE               "Nombre de vie :"
#define TEXT_TIME               "Temps de jeu :"
#define TEXT_NULL_GAME          "La partie est nul"

#define TEXT_LVL_1              "0 =  Carte 1"
#define TEXT_LVL_2              "1 =  Carte 2"
#define TEXT_LVL_3              "2 =  Carte 3"
#define TEXT_LVL_4              "3 =  Carte 4"
#define TEXT_LVL_5              "4 =  Carte 5"
#define TEXT_LVL_6              "5 =  Carte 6"
#define TEXT_LVL_7              "6 =  Carte 7"
#define TEXT_LVL_PERSO_1        "7 =  Carte perso 1"
#define TEXT_LVL_PERSO_2        "8 =  Carte perso 2"
#define TEXT_LVL_PERSO_3        "9 = Carte perso 3"
#define TEXT_RANDOM_LVL         "R = Carte aleatoire"

#define PATH_BLOC_TEXTURE       "../assets/map_imgs/bloc.jpg"
#define PATH_WALL_TEXTURE       "../assets/map_imgs/wall.jpg"
#define PATH_BACKGROUND_TEXTURE "../assets/map_imgs/background.jpg"
#define PATH_BOMB_TEXTURE       "../assets/map_imgs/bomb.png"
#define PATH_PLAYER_TEXTURE     "../assets/map_imgs/sprites.png"
#define PATH_EXPLOSION_TEXTURE     "../assets/map_imgs/explosion.png"

#define PATH_FONT               "../assets/fonts/open_sans_regular.ttf"
#define PATH_FONT_BOLD          "../assets/fonts/open_sans_bold.ttf"

#define PATH_LVL_1              "../assets/maps/lvl_1.txt"
#define PATH_LVL_2              "../assets/maps/lvl_2.txt"
#define PATH_LVL_3              "../assets/maps/lvl_3.txt"
#define PATH_LVL_4              "../assets/maps/lvl_4.txt"
#define PATH_LVL_5              "../assets/maps/lvl_5.txt"
#define PATH_LVL_6              "../assets/maps/lvl_6.txt"
#define PATH_LVL_7              "../assets/maps/lvl_7.txt"
#define PATH_LVL_PERSO_1        "../assets/maps/lvl_perso_1.txt"
#define PATH_LVL_PERSO_2        "../assets/maps/lvl_perso_2.txt"
#define PATH_LVL_PERSO_3        "../assets/maps/lvl_perso_3.txt"

#endif
