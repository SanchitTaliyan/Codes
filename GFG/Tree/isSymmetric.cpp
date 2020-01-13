#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int key;
    Node *left, *right;
};

bool check(Node *r1, Node *r2) {
    if(!r1 || !r2) {
        return r1 == r2
    }

    if(r1->key != r2->key) return false;

    return (check(r1->left, r2->right) && check(r1->right, r2->left));
}

bool isSymmetric(Node *root) {
    return check(root->left, root->right);
}