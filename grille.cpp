#include <cstddef>
#include <iostream>
#define COL 3
#define LINE 4
#define nbre_jeton 3


class plateau{
  public :
  std::byte player = std::byte{1};
  std::byte grid[LINE][COL] = {std::byte{0}};
  int last_x;
  int last_y;


  int play(int x){
    int y = LINE - 1;
    if (grid[y][x] != std::byte{0})
      return 0;
    --y;
    while (y != -1){
      if (grid[y][x] != std::byte{0}){
        grid[y + 1][x] = player;
        player = ~player;
        last_x = x;
        last_y = y + 1;
        return 1;
      }
      y--;
    }
    grid[0][x] = player;
    player = ~player;
    last_x = x;
    last_y = 0;

    return 1;
  }

  std::byte getPlayer(){
    return player;
  }

  void display(){
    for (int j = LINE - 1; j >= 0; j--){
      for (int i = 0; i < COL; i++){
        if (grid[j][i] == std::byte{254})
          std::cout << "x";
        else if (grid[j][i] == std::byte{1})
          std::cout << "O";
        else
          std::cout << ".";
      }
      std::cout  << "\n";
    }
  }

  int end(){
    for (int i = 0; i < COL; i++){
      if (grid[0][i] == std::byte{0})
        return 0;
    }
    return 1;
  }

  int verification(){
    int y = last_y;
    int x = last_x;
    int acc1 = 0;
    int acc2 = 0;
    int i;
    int j; 

    // recule jusqua la fin de la grille (rembobine)
    while( x > 0 || grid[y][x - 1]!= player){
      grid[y][x] = grid[y][x - 1];
      x--;
    }
    // verification horizontale 
    for(j = y; j < nbre_jeton; j++){
      for(i = x; x < nbre_jeton; i++){
        if(grid[j][i] == std::byte{1} &&  x < COL){
          acc1 +=1;
          acc2 = 0;
          x++;
        }
        if(grid[j][i] == std::byte{254} && x < COL){ 
          acc2 += 1;
          acc1 = 0;
          x++;   
        }
      }
    }
    if(acc1 != nbre_jeton && acc2 != nbre_jeton){
      return 0;
    } 
    if(acc1 == nbre_jeton || acc2 == nbre_jeton){
      return 1;
    }
    return acc1;
  }
};


int main(){

	plateau game;
  game.play(2);
  game.play(2);
  game.play(2);
  game.play(2);
  game.play(0);
  game.play(0);
  game.play(1);
  game.play(1);
  game.verification();
  game.getPlayer();
  game.display();
  game.end();

  return 0; 
}
