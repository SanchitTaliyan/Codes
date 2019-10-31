#include<iostream>

using namespace std;

struct Node{
  struct Node* left, *right;
  int val;
};

void BToDll(Node *root, Node** hRef){
  if(root == NULL) return;

  BToDll(root->right, hRef);
  root->right = *href;

  if(hRef != NULL){
    *hRef->left = root;
  }
  *href = root;
  BToDll(root->left, hRef);
}
