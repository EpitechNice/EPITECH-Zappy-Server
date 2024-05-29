##
## EPITECH PROJECT, 2022
## IO lib
## File description:
## makefile
##

SRC	=	src/log.c

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

FLAGS	=	-I./includes/	\
			-I./../linked_list/includes/	\
			-Wall		\
			-Wextra		\
			-L./../linked_list	\
			-llinked_list	\
			-g3

COMP	=	gcc

all:	$(BIN)

$(BIN):	$(OBJ)
	@ar rc $(BIN) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(BIN)

re: fclean all

%.o: %.c
	@echo $(GREEN)">> Compiling C object $@"$(RESET)
	@$(COMP) $(FLAGS) -c -o $@ $<

.PHONY: all clean fclean re
