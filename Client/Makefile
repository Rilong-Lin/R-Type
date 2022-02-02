##
## EPITECH PROJECT, 2021
## B-CPP-501-PAR-5-1-rtype-jonathan.layduhur
## File description:
## Makefile Test
##


MAKE		=	make
RM			=	-@rm -rf
CC			=	g++
PREFIX		=	src/

FILES		=	../main.cpp					\
				Menu.cpp

SRC			=	$(addprefix $(PREFIX), $(FILES))

OBJ			=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I./include -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio -I./include/ -std=c++17
CFLAGS		=	-Wextra -W -Wall

NAME		=	ok

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS)

vg:	CFLAGS += -g3
vg:	all

clean:
	$(RM) $(OBJ) vg*

fclean:	clean
	$(RM) $(NAME) vg*

re:	fclean all

.PHONY:	all clean fclean vg re
