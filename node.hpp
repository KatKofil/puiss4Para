#ifndef _NODE_HPP_
#define _NODE_HPP_

#include "utils.hpp"
#include "grille.hpp"

class Node{
  public:
    int level;
    int heuri;
    int nbSucces;
    plateau etat;
    Node *parent;
    std::vector<Node *> succes;

    Node(){
      level = 0;
      nbSucces = 0;
      heuri = 0;
      etat = plateau();
      parent = nullptr;
      succes.clear();
    }

    ~Node(){
      
    }

    void Barre(char Car, int nbCar);
    void display_node();
    void display_arbre();

    void create_succes(int _nbSucces);

    void cal_level();

};

#endif
