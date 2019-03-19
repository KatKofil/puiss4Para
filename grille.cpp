#include <cstddef>
#include <iostream>

#define COL 3
#define LINE 4


class plateau{
  public :
  std::byte player = std::byte{1};
	std::byte grid[LINE][COL] = {std::byte{0}};


	void play(int x){
     int y = LINE;
    while (y != 0){
      if (grid[y][x] != std::byte{0}){
        if (y + 1 < LINE){
          grid[y + 1][x] = player;
          player = ~player;
        }
        break;
      }
      y--;
    }
  }

  std::byte getPlayer(){
    return player;
  }

  void display(){
    for (int j = LINE; j > -1; j--){
      for (int i = 0; i < COL; i++){
        std::cout << (int)grid[j][i];
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

};


int main(){
  
}
