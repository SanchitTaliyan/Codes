#include<iostream>

using namespace std;

struct node{
  int key;
  node *left, *right;
};

struct node* newNode(int k){
  struct node* temp = new node;
  temp->key = k;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *root){
  if(root != NULL){
    inorder(root->left);
    cout<<root->key <<" ";
    inorder(root->right);
  }
}

struct node* minValueNode(struct node *node){
  struct node* current = node;
  while(current && current->left != NULL){
    current = current->left;
  }
  return current;
}

struct node* insert(struct node *root, int k){
  if(root == NULL) return newNode(k);
  if(k > root->key){
    root->right = insert(root->right, k);
  }
  else root->left = insert(root->left, k);
  return root;
}

struct node* deleteNode(struct node* root, int key){
  if(root == NULL) return root;

  if(key < root->key)
    root->left = deleteNode(root->left, key);

  else if(key > root->key)
    root->right = deleteNode(root->right, key);

  else{
    if(root->left == NULL){
      struct node* temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL){
      struct node* temp = root->left;
      free(root);
      return temp;
    }
    struct node* temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

int main(){
  struct node* root = newNode(50);
  root = insert(root, 30);
  root = insert(root, 70);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 60);
  root = insert(root, 80);

  cout<<"Inorder traversal for original"<<endl;
  inorder(root);
  cout<<"\nDelete 20\n";
  deleteNode(root,20);
  cout<<"Inorder traversal of modified tree:\n";
  inorder(root);
  cout<<"\n Delete 30\n";
  deleteNode(root,30);
  inorder(root);
  return 0;
}
