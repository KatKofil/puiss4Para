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
 

  node.display_arbre();*/
  std::vector<int> playout_succes;
  while(depth > 0){
    node.create_succes(playout.size());
    for (unsigned int i = 0; i < playout.size(); i++)
      node.succes[i]->etat.play(playout[i]);
    for(unsigned int i = 0; i < playout_succes.size();i++){
      playout_succes.clear();
      playout_succes = node.succes[i]->etat.move_dispo(node.succes[i]->etat.grid);
      node.succes[i]->create_succes(playout_succes.size());
      for (unsigned int j = 0; j < playout.size(); j++)
        node.succes[j]->succes[j]->etat.play(playout_succes[j]);
    }
    depth--;
  }
  node.display_arbre();
  return 0;
}
