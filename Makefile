##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=	./src/main_radar.c			\
			./src/arr_functions.c 			\
			./src/parsing/parse_file.c		\
			./src/display/game_init.c		\
			./src/display/display_clock.c		\
			./src/events.c				\
			./src/parsing/sprite_setup.c		\
			./src/plane_behavior/collisions.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	my_radar

CFLAGS	=	-W -Wall -lm -g -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C lib/my
	@gcc -o $(NAME) $(OBJ) -lm -lcsfml-window -lcsfml-system -lcsfml-graphics -L./lib/my -lmy
clean:
	@make -C lib/my clean
	@rm -f $(OBJ)
fclean: clean
	@make -C lib/my fclean
	@rm -f $(NAME)
re:		fclean all
.PHONY: clean
