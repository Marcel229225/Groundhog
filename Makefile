##
## EPITECH PROJECT, 2022
## MAkefile
## File description:
## makefile
##

SRC	=	$(shell echo *.cpp)

OBJ	=	$(SRC:.c=.o)

NAME	=	groundhog

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(SRC) -std=c++2a -Wall -Wextra -Werror

clean:
	rm -f *.o
	rm -f *.~

fclean:	clean
	rm -f $(NAME)

re:	fclean all
