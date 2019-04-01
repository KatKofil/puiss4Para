#ifndef _MCTS_HPP_
#define _MCTS_HPP_

#include "utils.hpp"

class MCTS{
  public:
    void playout(std::byte grid[LINE][COL]);
    void init(std::byte grid[LINE][COL]);
    void displayPlayout();

    std::vector<int> play;
    std::vector<std::vector<int>> result;
};

#endif
