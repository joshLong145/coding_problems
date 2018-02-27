#include <iostream>
#include <string>
struct Node{
  Node(int x) { data = x;}
  Node *left;
  Node *right;
  int data = 5;
};

class SerializeBT{
public:
  void inorder(Node *root){
    if(root != nullptr){
      inorder(root->left);
      std::cout << root->data << std::endl;
      inorder(root->right);
    }
  }
  void serializeBT(Node *&root){
    if(root == nullptr){
      stringData += "n";
      return;
    }
    stringData += std::to_string(root->data);
    serializeBT(root->left);
    serializeBT(root->right);
  }

  void deserializeBT(Node *&root){
    if(stringData[charCount] == 'n'){
      return;
    }

    root = new Node(stringData[charCount] - '0');
    charCount++;
    deserializeBT(root->left);
    deserializeBT(root->right);
  }
private:
  std::string stringData;
  int charCount = 0;
};



int main(){
  Node *root = new Node(1);
  root->left = new Node(1);
  root->right = new Node(4);
  root->left->left = new Node(3);
  root->left->right = new Node(5);
  root->left->right->right = new Node(7);

  SerializeBT ser;
  ser.inorder(root);
  ser.serializeBT(root);
  std::cout << "----------" << std::endl;
  Node *newRoot;
  ser.deserializeBT(newRoot);
  ser.inorder(newRoot);
  return 0;
}

