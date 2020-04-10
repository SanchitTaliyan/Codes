#include<iostream>
#include<algorithm>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

bool printPath(Node *root, Node *targetLeaf) {
    if(root == NULL || targetLeaf == NULL) return;

    if(root == targetLeaf || printPath(root->left, targetLeaf) || printPath(root->right, targetLeaf)) {
        cout << root->data << " ";
        return true;
    }

    return false;
}

void maxSumPath(Node *root, int *maxSumLeaf, int currSum, Node *targetLeaf) {
    if(root == NULL) return;
    currSum += root->data;

    if(root->left == NULL && root->right == NULL) {
        if(currSum > *maxSumLeaf) {
            *maxSumLeaf = currSum;
            *targetLeaf = *root;
        }
    }

    maxSumPath(root->left, maxSumLeaf, currSum, targetLeaf);
    maxSumPath(root->right, maxSumLeaf, currSum, targetLeaf);
}

int maxSum(Node *root) {
    if(root == NULL) return 0;
    int maxSumLeaf = INT_MIN;
    Node *targetLeaf;

    maxSumPath(root, &maxSumLeaf, 0, targetLeaf);

    printPath(root, targetLeaf);
}