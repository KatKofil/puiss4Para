NAME = Puiss4MinMax

CC = g++

SRC = grille.cpp minimax.cpp main.cpp node.cpp

FLAGS = -Wall -Werror -Wextra -g -std=c++17 -pthread

RM = rm -f

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
