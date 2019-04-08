#include "node.hpp"


void Node::cal_level(){
  if(parent != nullptr)
    level = parent->level + 1;
  else
    level = 0;
}

void Node::define_nbSucces(int _nbSucces){
  nbSucces = _nbSucces;
}

void Node::Barre(char Car, int nbCar){
  for (int i = 0; i < nbCar; i++)
    std::cout << Car;
}

void Node::display_node(){
  Barre(' ',2 * level);
  std::cout << "+ Noeud (" << this << ") :" << "\n";
  Barre(' ',2 * level);
  std::cout << "  - Niveau = " << level << "\n";
	Barre(' ',2 * level);
  std::cout << "  - nbSuccesseurs = " << nbSucces << "\n";
	Barre(' ',2 * level);
  std::cout << "  - Predecesseur = " << parent << "\n";
	Barre(' ',2 * level);
  std::cout << "  - Successeurs[" << nbSucces  << "] = { "; 
	for(int i=0; i < nbSucces; i++) {
		if(i>0) {
      std::cout << ", ";
		}
    std::cout << succes[i]->level;
	}

  std::cout << " }" << "\n";
  std::cout << "\n";
}

void Node::display_arbre(){
  display_node();
  for (int i = 0; i < nbSucces; i++)
	  succes[i]->display_arbre();
}




void Node::create_succes(int _nbSucces){
  
  this->nbSucces = _nbSucces;
  for (int i = 0; i < _nbSucces; i++){
  	Node *tmp = new Node;
    tmp->etat.upload(etat.grid);
    tmp->etat.player = this->etat.player;
    tmp->parent = this;
    tmp->cal_level();
    succes.push_back(tmp);
  }
}



void Node::suppr_node_succes(){
/*  for (int i = 0; i < nbSucces; i++){
    delete succes[i];
  }
  supprSucces();*/
}

int Node::create_tree(Node *node){
  std::vector<int> playout = node->etat.move_dispo(node->etat.grid);

  node->etat.display();
  if (node->etat.end() == 1 || node->etat.verification() != std::byte{0}){
    return 0;
  }
  else {
    node->create_succes(playout.size());
    for (unsigned int i = 0; i < playout.size(); i++){
      node->succes[i]->etat.play(playout[i]);
    }
    for (unsigned int i = 0; i < playout.size(); i++){
      create_tree(node->succes[i]);
    }
  }
  return 0;
}

