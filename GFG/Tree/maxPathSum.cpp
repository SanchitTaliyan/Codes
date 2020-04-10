#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node (int x) {
        data = x;
        left = right = NULL;
    }
};

int maxPathSumUtil(Node *root, int &res) {
    if(root == NULL) return 0;
    
    if(!root->left && !root->right) return root->data;

    int ls = maxPathSumUtil(root->left, res);
    int rs = maxPathSumUtil(root->right, res);

    if(root->left && root->right) {
        res = max(res, ls + rs + root->data);

        return max(ls, rs) + root->data;
    }

    return (!root->left) ? rs + root->data : ls + root->data;
}

// function to find the maximum sum of the path from one leaf node to another leaf node
int maxPathSum(Node *root) {
    int res = INT_MIN;
    maxPathSumUtil(root, res);
    
    return res;
}