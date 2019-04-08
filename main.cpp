#include "grille.hpp"
#include "minimax.hpp"
#include "node.hpp"

int main(){
	
	//int collum = 0;
  //std::byte winner;
	plateau game;
  
  Minimax bot;

  Node tree;
  bot.minimax(&tree, 0);

  //for (int i = 0; i < tree.nbSucces; i++){
  //  tree.succes[i]->etat.display();
  //}

  
  /*
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

		collum = 0;
		game.display();
    winner = game.verification();
		if(winner != std::byte{0}){
      std::cout << "Le winner est " << (int)winner << "\n";
			break;
		} 
	}
  */
	return 0; 
}
