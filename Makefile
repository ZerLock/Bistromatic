##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=	$(wildcard *.c) $(wildcard ./infin_add/*.c) \
		$(wildcard ./start/*.c) $(wildcard ./eval_expr/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -g3

LIB	=	-L./lib/my -lmy

NAME	=	calc

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./lib/my

re:	fclean all
