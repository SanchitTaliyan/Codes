bool preOrder(struct TreeNode* A, struct TreeNode* B){
  if(!A || !B)
    return A == B;
  if(A->val != B->val) return false;
  return (preOrder(A->left, B->left) && preOrder(A->right, B->right));
}
