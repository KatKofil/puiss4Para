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

/*
int Minimax::minimax(Node *node, int depth){ 
  std::vector<Node *> pile;
  pile.push_back(node);
  std::vector<int> playout;

  while(depth > 0){
    auto it = pile.end();
    std::cout << "Bien sur c'est apres\n";
    playout = (*it)->etat.move_dispo(&((*it)->etat.grid));
    (*it)->create_succes(playout.size());
    for(unsigned int i = 0; i < playout.size();i++){
      playout.clear();
      playout = (*it)->succes[i]->etat.move_dispo(&((*it)->succes[i]->etat.grid));
      (*it)->succes[i]->create_succes(playout.size());
    }
    for (unsigned int j = 0; j < playout.size(); j++)
      (*it)->succes[j]->etat.play(playout[j]);
    depth--;
  }
  return 0;
}
*/

/*
int minimax(Node *node,//int depth){
  int value;
  if(int(node->etat.who_win(WIN))){
    return int(node->etat.who_win(WIN));

  }
  
  if(node->etat.player == std::byte{1}){
    value = std::numeric_limits<int>::min();
    for(int i = 0; i < node->nbSucces;i++){
      //std::max(value,minimax(node->nbSucces,depth - 1,false));
    }
    return value;
  }
  if(node->etat.player == std::byte{254}){
     value = std::numeric_limits<int>::max();
  }

  for(int i = 0; i < node->nbSucces;i++){
      //std::min(value,minimax(node->nbSucces,depth - 1,true));
    }
    return value;
  }
*/





