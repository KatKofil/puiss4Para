#include "grille.hpp"


	void MCTS::playout(std::byte grid[LINE][COL]){
		play.clear();
		for (int i = 0; i < COL; i++){
			if (grid[LINE - 1][i] == std::byte{0}){
				play.push_back(i);
			}
		}
	}

  void MCTS::init(std::byte grid[LINE][COL]){
    playout(grid);
    int nb_thread = play.size();
    for (int j = 0; j < nb_thread; j++){
      result.push_back(std::vector<int>());
    }
    for (int i = 0; i < COL; i++){
      result[i].push_back(0);
      result[i].push_back(0);
      result[i].push_back(0);
    }
    for(int j = 0; j < COL; j++){
      for (int i = 0; i < 3; i++){
        std::cout << result[j][i] << " ";
      }
      std::cout << "\n";
    }
  }

 /* void MC(std::byte grid[LINE][COL]){
    for (int i = 0; i < ITE; i++){

    }
  }*/

	void MCTS::displayPlayout(){
		for (int i : play){
			std::cout << i + 1 << " ";
		}
		std::cout << "\n";
	}

