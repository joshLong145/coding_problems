#include <iostream>
/*
  10
  / \
 5  20
/ \ /
3 7 15
*/

void inOrderTraversal(Node *node){
  if(node != nullptr){
    inOrderTraversal(node->left);
    std::cout << node->data << std::endl;
    inOrderTraversal(node->right);
  }
}
