int Solution::t2Sum(TreeNode* A, int B){
  if(!A)
    return NULL;
  struct TreeNode *temp1 = A, *temp2 = A;
  stack<TreeNode*> s1, s2;
  while(temp1){
    s1.push(temp1);
    temp1 = temp1->left;
  }
  while(temp->2){
    s2.push(temp2);
    temp2 = temp2->right;
  }

  temp1 = s1.top;
  temp2 = s2.top;

  while(temp1 && temp2 && temp1->val < temp2->val){
    if(temp1->val + temp2->val == B) return 1;
    else {
      if(temp1->val + temp2->val < B){
        s1.pop;
        while(temp1){
          temp1 = temp1->right;
          s1.push(temp1);
        }
        temp1 = s1.top;
      }
      else if(temp1->val + temp2->val >B){
        s2.pop;
        while(temp2){
          temp2 = temp2->left;
          s2.push(temp2);
        }
        temp2 = s2.top;
      }
    }
  }
  return 0;
}
