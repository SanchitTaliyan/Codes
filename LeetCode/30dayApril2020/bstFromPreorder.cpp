#include<iostream>
#include<vector>

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
class Solution {
public:
    
    TreeNode* bstFromPreorderUtil(vector<int> &preorder, int *rootIndex, int low, int high, int size){
        if(*rootIndex >= size or low > high) return NULL;
        
        TreeNode* root = new TreeNode(preorder[*rootIndex]);
        *rootIndex = *rootIndex + 1;
        
        if(low == high) return root;
        
        int i;
        for(i = low; i <= high; i++){
            if(preorder[i] > root -> val)
                break;
        }
        
        root->left = bstFromPreorderUtil(preorder, rootIndex, *rootIndex, i - 1, size);
        root->right = bstFromPreorderUtil(preorder, rootIndex, i, high, size);
        
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int size = preorder.size();
        int rootIndex = 0;
        return bstFromPreorderUtil(preorder, &rootIndex, 0, size - 1, size);
    }
};