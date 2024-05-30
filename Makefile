##
## EPITECH PROJECT, 2024
## Zappy GUI
## File description:
## Makefile
##


SRC		=   $(wildcard src/*.c)			\
			$(wildcard src/parsing/*.c)	\
			$(wildcard src/server/*.c)	\
			$(wildcard src/server/init/*.c)	\
			$(wildcard src/server/running/*.c)	\
			$(wildcard src/clients/*.c)	\
			$(wildcard src/utils/*.c)	\

OBJ 	= 	$(patsubst src/%.c,compiled_object/%.o,$(SRC))

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

BIN	=	"zappy_server"

FLAGS	=	-Wall 				\
			-Wextra				\
			-Wfloat-equal 		\
			-Wundef 			\
			-Wcast-align		\
			-Wshadow			\
			-Wlogical-op		\
			-Wredundant-decls	\
			-O2

INCLUDES	=	-I./libs/includes	\
				-I./includes		\

LIBS	=	-L./libs		\
			-lheap	\
			-lmlist	\
			-linput_output		\

COMP	=	gcc

.PHONY:	all
all:	$(BIN)

$(BIN):	libs $(OBJ)
	@echo $(BOLD)$(GREEN)"Objects Done"$(RESET)
	@echo $(BOLD)$(PURPLE)"Compiling $(BIN)..."$(RESET)
	@$(COMP) -o $(BIN) $(OBJ) $(FLAGS) $(INCLUDES) $(LIBS)
	@make ascii

.PHONY:	libs
libs:
	@if [ -n "$$(ls -A libs | grep -vE '(^includes$$|^Makefile$$)')" ]; then \
		echo $(BOLD)$(PURPLE)"Making Libs..."$(RESET); \
		make --no-print-directory -C libs COLOR="$(COLOR)"; \
		echo $(BOLD)$(GREEN)"Libs Done\n\n"$(RESET); \
	fi
	@echo $(BOLD)$(PURPLE)"Compiling objects..."$(RESET)

clean:
	@if [ -n "$$(ls -A libs | grep -vE '(^includes$$|^Makefile$$)')" ]; then \
		make --no-print-directory -C libs clean; \
	fi
	@rm -rf compiled_object
	@rm -rf vgcore*

fclean: clean
	@if [ -n "$$(ls -A libs | grep -vE '(^includes$$|^Makefile$$)')" ]; then \
		make --no-print-directory -C libs fclean; \
	fi
	@rm -rf $(BIN)

re: fclean all

compiled_object/%.o: src/%.c
	@mkdir -p $(@D)
	@$(COMP) $(FLAGS) $(INCLUDES) $(LIBS) -g3 -c -o $@ $<
	@echo $(GREEN)">> compiling $<"$(RESET)

cs:	fclean
	./tests/run_coding_style.sh

ascii:
	@echo $(BOLD)$(PURPLE)
	@echo "\t       | $(BIN) compilation is done ✿"
	@echo "\t /\_/\ +-----------------------------------"
	@echo "\t( o.o )"
	@echo "\t > ^ <"
	@echo $(RESET)
