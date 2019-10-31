struct TreeNode{
  int val;
  TreeNode *left, *right;
};

int findMid(int start, int end){
  int mid = start + (end-start)/2;
  return mid;
}

struct TreeNode* solve(vector<int> &A, int start, int end){
  if(start<end)
    return NULL;
  int index = findMid(start, end);
  TreeNode* root = new TreeNode(A[index]);
  root->left = solve(A, start, index-1);
  root->right = solve(A, index+1, end);
  return root;
}
