#include "node.hpp"

void Node::cal_level(){
  if(parent != pN_NULL)
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
  std::cout << "+ Noeud (" << this << ") :" << std::endl;
/*Barre(' ',2*Niveau);
	cout << "  - Niveau = " << Niveau << endl;
	Barre(' ',2*Niveau);
	cout << "  - nbSuccesseurs = " << nbSuccesseurs << endl;
	Barre(' ',2*Niveau);
	cout << "  - Predecesseur = " << Predecesseur << endl;
	Barre(' ',2*Niveau);
	cout << "  - Successeurs[" << nbSuccesseurs  << "] = { ";
	for(int i=0; i<nbSuccesseurs; i++) {
		if(i>0) {
			cout << ", ";
		}
		cout << Successeurs[i];
	}
	cout << " }" << endl;
	cout << endl;*/
}

void Node::display_arbre(){
  display_node();
  for (int i = 0; i < nbSucces; i++)
    Node::succes[i]->display_arbre();
}

void initSucces(int _nbSucces){
  if (succes != pN_NULL)

}
