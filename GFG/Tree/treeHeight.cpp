#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

//function to find the height of a binary tree
int height(Node *node) {
    /*
    int height = 0;
    queue<Node*> q;
    q.push(node);
    Node *temp = new Node(-1);
    q.push(temp);

    while(!q.empty()) {
        Node* top = q.front();
        q.pop();
        if(top == temp && !q.empty()){
            height++;
            q.push(top);
        }

        else {
            if(top->left) {
                q.push(top->left);
            }
            if(top->right) {
                q.push(top->right);
            }
        }
    }
    return height + 1;
    */

   //another method with constant extra space
   if(!node) return 0;

   int lHeight = height(node->left);
   int rHeight = height(node->right);

   if(lHeight > rHeight) return lHeight + 1;

   else return rHeight + 1;
}