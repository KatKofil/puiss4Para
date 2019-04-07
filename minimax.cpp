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

int Minimax::minimax(Node node, int depth){
  std::vector<int> playout = node.etat.move_dispo(node.etat.grid);
  /*
  node.create_succes(playout.size());
  for (unsigned int i = 0; i < playout.size(); i++){
    node.succes[i]->etat.play(playout[i]);
    node.succes[i]->etat.display();
    std::cout << "\n\n";
  }

  node.display_arbre();*/
  std::vector<int> playout_succes;
  Node *tmp;  
  while(depth > 0){
    node.create_succes(playout.size());
    for(unsigned int i = 0; i < playout_succes.size();i++){
      tmp = node.succes[i];
      playout_succes.clear();
      playout_succes = tmp->etat.move_dispo(tmp->etat.grid);
      tmp->create_succes(playout_succes.size());
    }
    depth--;
  }
  node.display_arbre();
  return 0;
}
