#include "grille.hpp"
#include "minimax.hpp"
#include "node.hpp"

void create_tree(Node *node){
  std::vector<int> playout = node->etat.move_dispo(node->etat.grid);

  if (node->etat.end() == 1 || node->etat.verification() != std::byte{0})
    return;
  else {
    node->create_succes(playout.size());
    for (unsigned int i = 0; i < playout.size(); i++){
      node->succes[i]->etat.play(playout[i]);
    }
    for (unsigned int i = 0; i < playout.size(); i++){
      create_tree(node->succes[i]);
    }
  }
  return;
}

void lauch_thread(unsigned int nb_thread, std::vector<Node *> succes, std::vector<std::thread> *thread){
  for (unsigned int i = 0; i < nb_thread; i++){
    thread->push_back(std::thread(create_tree, succes[i]));
  }
}

int main(){
	
	//int collum = 0;
  //std::byte winner;
	plateau game;
  std::vector<int> playout;
  std::vector<std::thread> toJoin;
  //Minimax bot;

  Node tree;
  //create_tree(&tree);
  playout = tree.etat.move_dispo(tree.etat.grid);
  //bot.minimax(&tree, 0);
  tree.create_succes(playout.size());
  for (unsigned int i = 0; i < playout.size(); i++){
    tree.succes[i]->etat.play(playout[i]);
  }
  lauch_thread(playout.size(), tree.succes, &toJoin);
  for (unsigned int i = 0; i < tree.succes.size(); i++){
    toJoin[i].join();
  }

  //create_tree(&tree);






  //tree.display_arbre();
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
