#ifndef _GRILLE_HPP_
#define _GRILLE_HPP_

#include "utils.hpp"

class plateau{
  public:
    int play(int x);
    std::byte getPlayer();
    void display();
    int end();
    int verification_horizontal();
    int verification_vertical();
    int verification_diagonal_gd();
    int verification_diagonal_dg();
    std::byte who_win(int acc);
    std::byte verification();
    void upload(std::byte grid[LINE][COL]);
    std::vector<int> move_dispo(std::byte grid[LINE][COL]);

    std::byte player = std::byte{1};
    std::byte grid[LINE][COL] = {std::byte{0}};
    int last_x;
    int last_y;

};

#endif
