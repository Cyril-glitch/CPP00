NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror
SRC = megaphone.cpp
OBJ = megaphone.o 

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

.PHONY: all clean fclean re

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: fclean all