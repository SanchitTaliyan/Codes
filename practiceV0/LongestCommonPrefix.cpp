string Solution::longestCommonPrefix(vector<string> &A) {
  int col = A[0].length();
  int row = A.size();
  string res = "";
  char c;
  for(int i = 0; i < col; i++){
    c = A[i];
    int count = 1;
    for(int i = 1 ; i<row; i++){
      if(c == A[i]) count++;
    }
    if(count == row){
      res += c;
    }
    else break;
  }
  return res;
}
