SRC= 	main.c

OBJ=    $(SRC:%.c=%.o)

CC= 	gcc

NAME=   bomberman

FLAGS= 	-Wall -pedantic -Wextra -Werror -std=c11 -pthread
CFLAGS= `sdl2-config --cflags`
LDFLAGS=`sdl2-config --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(CFLAGS) $(LDFLAGS)

all:	$(NAME)


clean:
		rm -f *.o

fclean:
		rm -f $(NAME)
		rm -f $(OBJ)

re:		fclean \
		all
