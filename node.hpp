#include "utils.hpp"

class Node;

typedef Node * pNode;
typedef pNode * ppNode;
const pNode pN_NULL=0;
const ppNode ppN_NULL=0;


class Node{
  public:
    int level;
    int nbSucces;
    std::byte grid[LINE][COL] = {std::byte{0}};
    pNode parent;
    ppNode succes;


    Node(){
      level = 0;
      nbSucces = 0;
      parent = pN_NULL;
      succes = ppN_NULL;
    }

    ~Node(){
      suppr_node_succes();
    }
    
    void Barre(char Car, int nbCar);
    void display_node();
    void display_arbre();

    void initSucces(int _nbSucces);
    void create_succes(int _nbSucces);
    void suppr_node_succes();
    void supprSucces();

    void cal_level();
    void define_nbSucces(int _nbSucces);
};
