#include "node.hpp"


void Node::cal_level(){
  if(parent != nullptr)
    level = parent->level + 1;
  else
    level = 0;
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
