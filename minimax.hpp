#ifndef _MINIMAX_HPP_
#define _MINIMAX_HPP

#include "utils.hpp"
#include "grille.hpp"
#include "node.hpp"

class Minimax{
  public:
    int best_move(plateau grid, int deth);
    int minimax(Node node, int depth);
};

#endif
