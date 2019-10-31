int inOrder(struct TreeNode *root, int K){
  if(root!=NULL){
    inOrder(root->left);
    k++;
    if(k == K)
      return root->val;
    inOrder(root->right);
    k++;
    if(k == K)
      return root->val;
  }
}
