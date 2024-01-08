int Solution::isPalindrome(string A) {
  int len = A.length();
  int l = 0, h = 0;
  transform(A.begin(), A.end(), A.begin(), ::tolower)
  char c;
  string str;
for(int i = 0; i<len; i++){
  c = A[i];
  if((c>='0' && c<='9') || (c>='a' && c<='z'){
    str.push_back(c);
  }
}
  h = str.length() - 1;
  while(l < h){
    if(str[l] != str[h]) return 0;
    l++;
    h--;
  }
  return 1;
}
