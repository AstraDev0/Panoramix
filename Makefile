##
## EPITECH PROJECT, 2023
## B-MAT-400-BER-4-1-201yams-matthis.brocheton
## File description:
## Makefile
##

SRC		=	$(wildcard ./src/*.c)	\

OBJ		=	$(SRC:.c=.o)

NAME	=	panoramix

LDFLAGS	=	-I ./include -g3 -lm

UNIT_TESTS	=	$(wildcard ./tests/*.c)	--coverage -lcriterion	\

$(NAME):
		gcc -o $(NAME) main.c $(SRC) $(LDFLAGS)

all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ./tests/*.vgcore
		rm -f ./tests/*.gcno
		rm -f ./tests/*.gcda
		rm -f ./tests/unit_tests

re:		fclean all

unit_tests:	fclean
		gcc -o ./unit_tests $(SRC) $(UNIT_TESTS) $(LDFLAGS)

tests_run:	unit_tests
		./unit_tests

.PHONY:	re fclean clean all
