##
## EPITECH PROJECT, 2022
## IO lib
## File description:
## makefile
##

SRC	=	$(wildcard src/input/*.c)	\
		$(wildcard src/log/*.c)

OBJ	=	$(SRC:%.c=%.o)

BIN	=	libinput_output.a

ifeq ($(COLOR), yes)
	RESET		= "\033[0m"
	BLUE		= "\033[34m"
	BOLD		= "\033[1m"
	FBLUE		= "\033[94m"
	FGREEN		= "\033[92m"
	FRED		= "\033[91m"
	FYELLOW		= "\033[93m"
	GREEN		= "\033[32m"
	PURPLE		= "\033[35m"
	RED			= "\033[31m"
	YELLOW		= "\033[33m"
else
	RESET		= ""
	BLUE		= ""
	BOLD		= ""
	FBLUE		= ""
	FGREEN		= ""
	FRED		= ""
	FYELLOW		= ""
	GREEN		= ""
	PURPLE		= ""
	RED			= ""
	YELLOW		= ""
endif

CFLAGS	=	-I./includes/	\
			-I./../dlist/includes/	\
			-Wall		\
			-Wextra		\
			-L./../dlist	\
			-ldlist	\
			-g3

CC	=	gcc

all:	$(BIN)

$(BIN):	$(OBJ)
	@ar rc $(BIN) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(BIN)

re: fclean all

.PHONY: all clean fclean re
