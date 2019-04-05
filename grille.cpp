#include "grille.hpp"
#include "MCTS.hpp"


int plateau::play(int x){
	int y = LINE - 1;
	if (grid[y][x] != std::byte{0})
		return 0;
	--y;
	while (y != -1){
		if (grid[y][x] != std::byte{0}){
			grid[y + 1][x] = player;
			player = ~player;
			last_x = x;
			last_y = y + 1;
			return 1;
		}
		y--;
	}
   // cas ou la colone est vide (premier pion de la colone)
	grid[0][x] = player;
	player = ~player;
	last_x = x;
	last_y = 0;
	return 1;
}

std::byte plateau::getPlayer(){
	return player;
}

void plateau::display(){
	for (int j = LINE - 1; j >= 0; j--){
		for (int i = 0; i < COL; i++){
			if (grid[j][i] == std::byte{254})
				std::cout << "x";
			else if (grid[j][i] == std::byte{1})
				std::cout << "O";
			else
				std::cout << ".";
		}
		std::cout  << "\n";
	}
}

int plateau::end(){
	for (int i = 0; i < COL; i++){
		if (grid[LINE - 1][i] == std::byte{0})
			return 0;
	}
	return 1;
}

int plateau::verification_horizontal(){
	int y = last_y;
	int x = last_x;
	int acc = 0;
	int i = x;

	while(i < COL && grid[y][i] == ~player)
		i++;
	i--;
	while(i >= 0 && grid[y][i] == ~player){
		acc ++;
		i--;
	}
	return acc;

}

int plateau::verification_vertical(){
	int y = last_y;
	int x = last_x;
	int acc = 0;
	int j = y;

	while(j < LINE && grid[j][x] == ~player)
		j++;
	j--;
	while(j >= 0 && grid[j][x] == ~player){
		acc ++;
		j--;
	}
	return acc;
}

int plateau::verification_diagonal_gd(){
	int y = last_y;
	int x = last_x;
	int acc = 0;
	int i = x;
	int j = y;
	while(j < LINE && i < COL && grid[j][i] == ~player){
		j++;
		i++;
	}
	i--;
	j--;
	while(j >= 0 && i >= 0 && grid[j][i] == ~player){
		acc++;
		j--;
		i--;
	}
	return acc;
}

int plateau::verification_diagonal_dg(){
	int y = last_y;
	int x = last_x;
	int i = x;
	int j = y;
	int acc =  0;
	while(j < LINE && i >= 0 && grid[j][i] == ~player){
		j++;
		i--;
	}
	i++;
	j--;
	while(j >= 0 && i < COL && grid[j][i] == ~player){
		acc++;
		j--;
		i++;
	}
	return acc;
}

std::byte plateau::who_win(int acc){
	if(acc == WIN){
		if(grid[last_y][last_x] == std::byte{1})
			return std::byte{1};
		if(grid[last_y][last_x] == std::byte{254})
			return std::byte{254};
	}
	return std::byte{0};
}

std::byte plateau::verification(){
	std::byte horizon = who_win(verification_horizontal());
	std::byte vertical = who_win(verification_vertical());
	std::byte diag_gd = who_win(verification_diagonal_gd());
	std::byte diag_dg = who_win(verification_diagonal_dg());

	if(horizon != std::byte{0})
		return horizon;
	if(vertical != std::byte{0})
		return vertical;
	if(diag_gd != std::byte{0})
		return diag_gd;
	if(diag_dg != std::byte{0})
		return diag_dg;
	return std::byte{0};
}
void plateau:: upload(std::byte grid[LINE][COL]){
		//std::byte copie[LINE][COL];

	memcpy(this->grid,grid,sizeof(std::byte[LINE][COL]));
}

std::vector<int> plateau::move_dispo(std::byte grid[LINE][COL]){
	std::vector<int> play;
	for (int i = 0; i < COL; i++){
		if (grid[LINE - 1][i] == std::byte{0}){
			play.push_back(i);
	
		}
	}
	return play;
}
