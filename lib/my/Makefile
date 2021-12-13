##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile for lib
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rcs $(NAME) $(OBJ)
	make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
