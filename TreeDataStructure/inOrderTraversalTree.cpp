vector<int> Solution::inorderTraversal(TreeNode* A) {
    if(!A) return NULL;
    stack<TreeNode*> s;
    TreeNode* pCurrent = A;
    vector<int> ans;
    while(!stack.empty() || pCurrent){
      if(pCurrent){
        stack.push(pCurrent);
        pCurrent = pCurrent->left;
      }
      TreeNode* temp = stack.top();
      stack.pop();
      ans.push_back(temp);
      pCurrent = temp->right;
    }
    return ans;
}
