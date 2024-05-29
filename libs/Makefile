##
## EPITECH PROJECT, 2022
## library
## File description:
## library
##

LIBS	=	linked_list	\
			display		\

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
	$(foreach lib, $(LIBS), make --no-print-directory -C $(lib) COLOR="$(COLOR)" ;)

cpAll:
	$(foreach lib, $(LIBS), cp $(lib)/lib$(lib).a ./ ;)
	$(foreach lib, $(LIBS), cp $(lib)/include/$(lib).h ./includes/ ;)

resetCp:
	$(foreach lib, $(LIBS), rm -f ./lib$(lib).a ;)
	$(foreach lib, $(LIBS), rm -f ./includes/$(lib).h ;)

makeClean:
	$(foreach lib, $(LIBS), make --no-print-directory -C $(lib) clean COLOR="$(COLOR)" ;)

makeFclean:
	$(foreach lib, $(LIBS), make --no-print-directory -C $(lib) fclean COLOR="$(COLOR)" ;)
