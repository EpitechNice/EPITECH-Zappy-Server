##
## EPITECH PROJECT, 2022
## dragusheen linked_list-library
## File description:
## makefile of the library
##

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:%.c=%.o)

NAME	=	libdlist.a

CFLAGS	=	-I./includes	\
			-Wall		\
			-Wextra		\
			-g3

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
