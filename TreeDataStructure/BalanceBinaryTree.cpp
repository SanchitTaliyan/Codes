#include<iostream>
#include<vector>

using namespace std;

struct Node{
  struct Node* left, *right;
  int data;
};

int height(struct Node* root){
  if(root == NULL) return 0;
  return max(1+height(root->left), 1+height(root->right));
}

bool balanceBinarySearchTree(struct Node* node){
  if(node == NULL) return true;
  int diff = abs(height(node->left) - height(node->right));
  return (balanceBinarySearchTree(node->left) && balanceBinarySearchTree(node->right) && diff<=1);
}
