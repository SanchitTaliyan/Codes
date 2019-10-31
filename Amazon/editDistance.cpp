int min(int a, int b, int c){
  return min(min(a, b), c);
}

int editDistance(string A, string B, int m, int n){
    if(m == 0) return n;
    if(n == 0) return m;

    if(A[m-1] == B[n-1]) return editDistance(A, B, m-1, n-1);
    return 1 + min(editDistance(A, B, m, n-1), editDistance(A, B, m-1, n), editDistance(A, B, m-1, n-1))

}

int Solution::minDistance(string A, string B) {
  int result = editDistance(A, B, A.size(), B.size());
  return result;
}
