##
## EPITECH PROJECT, 2019
## emacs
## File description:
## Makefile for lib
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I./

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re:		fclean all
.PHONY:	clean
