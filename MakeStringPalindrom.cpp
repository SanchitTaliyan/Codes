int isPalindrom(string A, int low, int high){
  while(low<high){
    if(A[low] != A[high]) return 0;
    low++;
    high--;
  }
  return 1;
}


int Solution::solve(string A) {
  int low = 0;
  int high = A.length() - 1;
  if(high == 0) return 0;
  int j;
  for(int j = high; j>=0; j--){
    int res = isPalindrom(A, low, j);
    if(res == 1) break;
  }
  int ans = A.length() - (j+1);
  return ans;
}
