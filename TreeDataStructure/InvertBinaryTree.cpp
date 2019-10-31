struct TreeNode* solve(struct TreeNode* A){
  if(!A)
    return NULL;
  struct TreeNode* temp = A->right;
  A->right = A->left;
  A->left = temp;
  solve(A->left);
  solve(A->right);
  return A;
}
