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
  
  std::vector<Node *> pile;
  pile.push_back(&node);
  std::vector<int> playout;
  while(depth > 0){
    auto it = pile.end();
    playout = (*it)->etat.move_dispo(node.etat.grid);
    std::cout << "Bien sur c'est apres\n";
    (*it)->create_succes(playout.size());
    for (unsigned int i = 0; i < playout.size(); i++)
      (*it)->succes[i]->etat.play(playout[i]);
    for(unsigned int i = 0; i < playout.size();i++){
      playout.clear();
      playout = (*it)->succes[i]->etat.move_dispo((*it)->succes[i]->etat.grid);
      (*it)->succes[i]->create_succes(playout.size());
      for (unsigned int j = 0; j < playout.size(); j++)
        node.succes[j]->succes[j]->etat.play(playout[j]);
    }
    depth--;
  }
  node.display_arbre();
  return 0;
}
