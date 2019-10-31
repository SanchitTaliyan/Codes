struct TreeNode{
  int val;
  TreeNode *left, *right;
};

struct TreeNode* solve(vector<int> V){
  int n = V.size();
  TreeNode *root = new TreeNode;
  root->val = V[n-1];
  TreeNode *it = root;
  for(int i = n-2; i>=0; i++){
    TreeNode *temp = new TreeNode;
    temp->val = V[i];
    it->left = temp;
    it = temp;
  }
}
