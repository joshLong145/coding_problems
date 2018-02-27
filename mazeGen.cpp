#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

#define HEIGHT 7
#define WIDTH 7

class DFSMaze{
private:
  std::vector<std::vector<int>> maze = std::vector<std::vector<int>> (HEIGHT, std::vector<int>(WIDTH));

  std::vector<int> randomDirs(){
    std::vector<int> randNums(4);
    for(int i = 0; i < 4; i ++){
      randNums[i] = (rand() % 4) -1;
    }
    return randNums;
  }

  void rec(int r, int c){
    std::vector<int> randDirs = randomDirs();

    for(int i =0; i < (int)randDirs.size(); i++){
      switch(randDirs[i]){

      case 1:
        if( r - 2 <= 0)
          continue;
        if(maze[r -2][c] != 0){
          maze[r-2][c] = 0;
          maze[r-1][c] = 0;
          rec(r-2,c);
        }
        break;
      case 2:
        if( c + 2 >= WIDTH -1)
          continue;
        if(maze[r][c+2] != 0){
          maze[r][c+2] = 0;
          maze[r][c+1] = 0;
          rec(r,c+2);
        }
        break;
      case 3:
        if(r + 2 >= HEIGHT - 1)
          continue;
        if(maze[r+2][c] != 0){
          maze[r+2][c] = 0;
          maze[r+1][c] = 0;
          rec(r +2, c);
        }
        break;
      case 4:
        if(c - 2 <= 0)
          continue;
        if(maze[r][c -2] != 0){
          maze[r][c -2] = 0;
          maze[r][c -1] = 0;
          rec(r,c - 2);
        }
        break;
      }
    }
  }
public:
  std::vector<std::vector<int>> generateMaze(){
    srand(time(NULL));
    for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
        maze[i][j] = 1;

    std::cout << "h" << std::endl;
    int r = rand() % HEIGHT;
    while(r % 2 == 0){
      r = rand() % HEIGHT;
    }

    int c = rand() % WIDTH;
    while(c % 2 == 0){
      c = rand() % WIDTH;
    }

    maze[r][c] = 0;

    rec(r, c);
    return maze;
  }

};

int main(){
  DFSMaze gen;
  std::vector<std::vector<int>> maze = gen.generateMaze();
  for(int i = 0; i < maze.size(); i ++){
    for(int j = 0; j < maze[i].size(); j++){
      std::cout << maze[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}
