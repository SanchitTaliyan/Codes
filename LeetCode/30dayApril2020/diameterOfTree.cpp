#include<iostream>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
int height (TreeNode* root) {
    if(root == NULL) return 0;
    
    return 1 + max(height(root->left), height(root->right));
}
*/

int diameter(TreeNode*root, int *height) {
    int lh = 0, rh = 0;
    
    int lDiameter = 0, rDiameter = 0;
    
    if(root == NULL) {
        *height = 0;
        return 0;
    }
    
    lDiameter = diameter(root->left, &lh);
    rDiameter = diameter(root->right, &rh);
    
    *height = max(lh, rh) + 1;
    
    return max((lh + rh ), max(lDiameter, rDiameter));
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        return diameter(root, &height);
    }
};