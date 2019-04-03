#include "utils.hpp"

class Node;



class Node{
  public:
    int level;
    int nbSucces;
    std::byte grid[LINE][COL] = {std::byte{0}};
    Node *parent;
    std::vector<Node> succes;


    Node(){
      level = 0;
      nbSucces = 0;
      parent = nullptr;
    }

    ~Node(){
      suppr_node_succes();
    }
    
    void Barre(char Car, int nbCar);
    void display_node();
    void display_arbre();

    void create_succes(int _nbSucces);
    void suppr_node_succes();
    void supprSucces();

    void cal_level();
    void define_nbSucces(int _nbSucces);
};
