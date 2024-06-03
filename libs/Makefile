##
## EPITECH PROJECT, 2024
## library
## File description:
## library
##

LIBS	=	heap	\
			mlist	\
			input_output	\
			dlist	\

all:
	@make --no-print-directory makeAll
	@make --no-print-directory cpAll

clean:
	@make --no-print-directory resetCp
	@make --no-print-directory makeClean

fclean: clean	makeFclean
	# @make --no-print-direcctory makeFclean

re: fclean all

.PHONY: all clean fclean re

makeAll:
	$(foreach lib, $(LIBS), make -C $(lib) COLOR="$(COLOR)" ;)

cpAll:
	$(foreach lib, $(LIBS), cp $(lib)/lib$(lib).a ./ ;)
	$(foreach lib, $(LIBS), cp $(lib)/includes/$(lib).h ./includes/ ;)

resetCp:
	$(foreach lib, $(LIBS), rm -f ./lib$(lib).a ;)
	$(foreach lib, $(LIBS), rm -f ./includes/$(lib).h ;)

makeClean:
	$(foreach lib, $(LIBS), make -C $(lib) clean COLOR="$(COLOR)" ;)

makeFclean:
	$(foreach lib, $(LIBS), make -C $(lib) fclean COLOR="$(COLOR)" ;)
