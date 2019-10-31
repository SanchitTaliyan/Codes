#include<iostream>
using namespace std;

struct TreeNode{
  int data;
  struct TreeNode* left, *right;
};

bool preOrder(struct TreeNode* A, struct TreeNode* B){
  if(A->data != B->data) return false;
  preOrder(A->left, B->left);
  preOrder(A->right, B->right);
}
