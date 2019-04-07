#include "minimax.hpp"

/*
int Minimax::best_move(plateau etat, int depth){

	int neutral_valu = std::numeric_limits<int>::min(); //0x80000000
	std::vector<int> choix;

	for(auto m : etat.move_dispo(etat.grid)){
		plateau tmp = etat;
		tmp.play(m);
	}



}*/

int Minimax::minimax(Node node){
  
  std::vector<int> playout = node.etat.move_dispo(node.etat.grid);
  
  node.create_succes(playout.size());
  node.succes[0]->etat.display();
  std::cout << "ca passe\n";
  for (unsigned int i = 0; i < playout.size(); i++){
    node.succes[i]->etat.play(playout[i]);
  }
  return 0;
}
