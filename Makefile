NAME = Puiss4MinMax

CC = g++

SRC = grille.cpp

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address -std=c++17

RM = rm -f

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
