#include <cstddef>
#include <iostream>
#include <vector>
#define COL 4
#define LINE 4
#define WIN 3



class MCTS{
public:
	std::vector<int> play;


	void playout(std::byte grid[LINE][COL]){
		play.clear();
		for (int i = 0; i < COL; i++){
			if (grid[LINE - 1][i] == std::byte{0}){
				play.push_back(i);
			}
		}
	}



	void displayPlayout(){
		for (int i : play){
			std::cout << i + 1 << " ";
		}
		std::cout << "\n";
	}
};


class plateau{
	public :
	std::byte player = std::byte{1};
	std::byte grid[LINE][COL] = {std::byte{0}};
	int last_x;
	int last_y;


	int play(int x){
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

	std::byte getPlayer(){
		return player;
	}

	void display(){
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

	int end(){
		for (int i = 0; i < COL; i++){
			if (grid[LINE - 1][i] == std::byte{0})
				return 0;
		}
		return 1;
	}

	int verification_horizontal(){
		int y = last_y;
		int x = last_x;
		int acc = 0;
		int i = x;

		while(i < COL && grid[y][i] == ~player){
			i++;
		}
		i--;
		while(i >= 0 && grid[y][i] == ~player){
			acc ++;
			i--;
		}
		return acc;

	}

	int verification_vertical(){
		int y = last_y;
		int x = last_x;
		int acc = 0;
		int j = y;

		while(j < LINE && grid[j][x] == ~player){
			j++;
		}
		j--;
		while(j >= 0 && grid[j][x] == ~player){
			acc ++;
			j--;
		}
		return acc;
	}

	int verification_diagonal_gd(){
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

	int verification_diagonal_dg(){
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
		printf("%d\n",acc);
		return acc;
	}

	int who_win(int acc){
		if(acc == WIN){
			if(grid[last_y][last_x] == std::byte{1}){
				std::cout << "Joueur 1 a gagner\n";
				return 1;
			}
			if(grid[last_y][last_x] == std::byte{254}){
				std::cout << "Joueur 2 a gagner\n";
				return 1;
			}
		}
		return 0;
	}
	int verification(){
		
		if(who_win(verification_horizontal())){
			return 1;
		}	
		if(who_win(verification_vertical())){
			return 1;
		}
		if(who_win(verification_diagonal_gd())){
			return 1;
		}
		if(who_win(verification_diagonal_dg())){
			return 1;
		}
		return 0;
	}
};


int main(){
	int collum = 0;
	plateau game;
	MCTS bot;

	while(1){
		while (collum < 1 || collum > COL){
			std::cout << "Enter a collum : ";
			std::cin >> collum;
		}
		if (game.end() == 1)
			return 0;
		while (game.play(collum - 1) != 1){
			std::cout << "Enter a valid collum : ";
			std::cin >> collum;
		}

		bot.playout(game.grid);
		bot.displayPlayout();
		collum = 0;
		game.display();
		if(game.verification() == 1){
			break;
		} 
	}
	return 0; 
}
