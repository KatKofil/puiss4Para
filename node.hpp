#ifndef _NODE_HPP_
#define _NODE_HPP_

#include "utils.hpp"
#include "grille.hpp"

class Node{
  public:
    int level;
    int nbSucces;
    plateau etat;
    Node *parent;
    std::vector<Node *> succes;

    Node(){
      level = 0;
      nbSucces = 0;
      //Les problème se trouve dans les 3 ligne suivante
      etat(new plateau);
      parent(new Node);
      succes(new std::vector);
    }

    void Barre(char Car, int nbCar);
    void display_node();
    void display_arbre();

    void create_succes(int _nbSucces);
    void suppr_node_succes();

    void cal_level();
    void define_nbSucces(int _nbSucces);
};

#endif
