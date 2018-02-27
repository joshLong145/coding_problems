#include <iostream>
#include <string>
#include <queue>
#include <vector>

// 0 are free space, 5's are walls and 9 is the exit
std::vector<std::vector<int>> maze=  {
                   {5,5,5,5,0,5,5,5,5},
                   {5,5,0,0,0,5,5,5,5},
                   {0,0,0,0,0,0,5,5,5},
                   {5,5,5,5,0,0,5,5,5},
                   {5,5,5,0,0,5,5,5,5},
                   {5,5,5,0,0,5,5,5,5},
                   {5,0,0,0,0,5,5,5,5},
                   {5,0,5,0,0,0,0,0,5},
                   {5,5,5,5,5,5,9,5,5}
};


class Node{
public:
  int x;
  int y;
  Node *parent;

  Node(int x, int y, Node *parent){
    this->x = x;
    this->y = y;
    this->parent = parent;
  }

  Node *  getParent(){
    return *&parent;
  }

  std::string toString(){
    return "x = " + std::to_string(x) + " y = " + std::to_string(y);
  }
};

bool isFree(int x, int y){
  if((x >= 0 && x < (int)maze.size()) && (y >= 0 && y < (int)maze[x].size()) && (maze[x][y] == 0 || maze[x][y] == 9)){
    return true;
  }
  return false;
}
std::queue<Node*> q;

Node * getBFSPath(int x, int y){
  q.push(new Node(x,y,nullptr));
  while(!q.empty()){
    Node *n = q.front();
    q.pop();
    if(maze[n->x][n->y] == 9){
      std::cout << "Exit has been reached" << std::endl;
      return n;
    }
    if(isFree(n->x +1,n->y)){
      maze[n->x][n->y] = 1;
      Node  *next = new Node(n->x+1,n->y,n);
      q.push(next);
    }
    if(isFree(n->x-1, n->y)){
      maze[n->x][n->y] = 1;
      Node  *next = new Node(n->x -1,n->y,n);
      q.push(next);
    }
    if(isFree(n->x,n->y +1)){
      maze[n->x][n->y] = 1;
      Node *next = new Node(n->x,n->y +1,n);
      q.push(next);
    }
    if(isFree(n->x,n->y -1)){
      maze[n->x][n->y] = 1;
      Node *next = new Node(n->x,n->y-1,n);
      q.push(next);
    }
  }
  return nullptr;
}


int main(){

  Node * p = getBFSPath(0,4);
  for(int i = 0; i < 9; i++){
    for(int j = 0; j< 9; j++){
      std::cout << maze[i][j];
    }
    std::cout << '\n';
  }
  std::cout << "PATH TAKEN" << std::endl;
  while(p->getParent() != nullptr){
    std::cout << p->toString() << std::endl;
    p = p->getParent();
  }

  return 0;
}


