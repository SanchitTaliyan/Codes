#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void bToDll(Node *root, Node **href) {
    if(root == NULL) return;

    bToDll(root->right, href);
    root->right = *href;
    if(*href != NULL) {
        *href->left = root;
    }

    *href = root;
    bToDll(root->left, href);
}