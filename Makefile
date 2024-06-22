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
			$(wildcard src/clients/handle_ai/*.c)	\
			$(wildcard src/clients/handle_gui/*.c)	\
			$(wildcard src/utils/*.c)	\

TEST_SRC		=	$(wildcard src/utils/*.c)	\
					$(wildcard src/parsing/*.c)	\
					$(wildcard src/server/*.c)	\
					$(wildcard src/server/init/*.c)	\
					$(wildcard src/server/running/*.c)	\
					$(wildcard src/clients/*.c)	\
					$(wildcard src/clients/handle_ai/*.c)	\
					$(wildcard src/clients/handle_gui/*.c)	\
					$(wildcard tests/*.c)	\
					$(wildcard tests/utils/*.c)	\

OBJ 		= 	$(patsubst src/%.c,obj/%.o,$(SRC))

TEST_OBJ 	= 	$(patsubst src/%.c,obj/%.o,$(TEST_SRC))

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

TEST_BIN	=	"unit_tests"

FLAGS	=	-Wall 				\
			-Wextra				\
			-Werror				\
			-Wfloat-equal 		\
			-Wundef 			\
			-Wcast-align		\
			-Wshadow			\
			-Wlogical-op		\
			-Wredundant-decls	\
			-g3					\
			-O2

TEST_FLAGS	=	--coverage 			\
				-lcriterion

INCLUDES	=	-I./libs/includes	\
				-I./includes		\

LIBS	=	-L./libs		\
			-ldlist	\
			-linput_output	\

COMP	=	gcc

.PHONY:	all
all:	$(BIN)

$(BIN):	libs $(OBJ)
	@echo $(BOLD)$(GREEN)"Objects Done"$(RESET)
	@echo $(BOLD)$(PURPLE)"Compiling $(BIN)..."$(RESET)
	@$(COMP) -o $(BIN) $(OBJ) $(TEST_FLAGS) $(INCLUDES) $(LIBS)
	@make ascii

$(TEST_BIN):	libs $(TEST_OBJ)
	@echo $(BOLD)$(GREEN)"Objects Done"$(RESET)
	@echo $(BOLD)$(PURPLE)"Compiling $(TEST_BIN)..."$(RESET)
	@$(COMP) -o $(TEST_BIN) $(TEST_OBJ) $(TEST_FLAGS) $(INCLUDES) $(LIBS)
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
	@rm -rf obj/
	@rm -rf vgcore*

fclean: clean
	@if [ -n "$$(ls -A libs | grep -vE '(^includes$$|^Makefile$$)')" ]; then \
		make --no-print-directory -C libs fclean; \
	fi
	@rm -rf $(BIN)
	@rm -rf $(TEST_BIN)
	@rm -rf *.gcda *.gcno

re: fclean all

obj/%.o: src/%.c
	@mkdir -p $(@D)
	@$(COMP) $(FLAGS) $(INCLUDES) $(LIBS) -g3 -c -o $@ $<
	@echo $(GREEN)">> compiling $@"$(RESET)

cs:	fclean
	./tests/run_coding_style.sh

tests_run: $(TEST_BIN)
	@./$(TEST_BIN)
	@make fclean

ascii:
	@echo $(BOLD)$(PURPLE)
	@echo "\t       | $(BIN) compilation is done ✿"
	@echo "\t /\_/\ +-----------------------------------"
	@echo "\t( o.o )"
	@echo "\t > ^ <"
	@echo $(RESET)
