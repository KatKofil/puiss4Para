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



/*
  int verification(){

    int y = last_y;
    int x = last_x;
    int acc = 0;
  
    while( x > 0 || grid[y][x - 1]!= player){
      grid[y][x - 1];
      x--

    }
    }

*/



    
  
};


int main(){

	plateau game;
  game.play(2);
  game.play(2);
  game.play(2);
  game.play(2);
	game.getPlayer();
	game.display();
	game.end();

	return 0;
  
}
