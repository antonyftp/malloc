##
## EPITECH PROJECT, 2021
## makefile
## File description:
## Malloc makefile
##

SRC		=	src/malloc.c 		\
			src/malloc_utils.c	\
			src/calloc.c 		\
			src/realloc.c 		\
			src/reallocarray.c 	\
			src/free.c			\

CFLAGS	= -O3 -fPIC -I include/ -Wall

OBJS	=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

all:	$(NAME)

$(NAME): $(OBJS)
	gcc -fPIC -shared -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

test:
	cd tests && make
	cd tests && mv malloctest ../

test-clean:
	cd tests && make fclean
	rm -f malloctest

.PHONY: all clean fclean re test test-clean