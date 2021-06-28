##
## EPITECH PROJECT, 2018
## makefile
## File description:
## palindrome makefile
##

SRC			=   main.c							\

NAME		=	malloctest

CFLAGS		+=	-std=gnu11 -I ../include/ -L../ -lmy_malloc

OBJ			=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ) $(CFLAGS)

debug:
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME) $(NAME_TEST)

re:	fclean all

.PHONY: 	all clean fclean re debug