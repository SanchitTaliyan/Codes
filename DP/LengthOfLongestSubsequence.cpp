int LLS(vector<int> &A, int n){
  if(n == 0 || n ==1 || n == 2) return n;
  vector<int> I(n);
  vector<int> D(n);
  I[0] = 1;
  D[n-1] = 1;
  vecor<int>result(n);
  for(int i = 1; i<n; i++){
    V[i] = 1;
    for(int j =0; j<i; j++){
      if(A[i] > A[j] && I[i] < I[j] + 1)
        I[i] = I[j] + 1;
    }
    for(int k = n-2; k>i; k--){
      D[k] = 1;
      for(int j = n-1; j>k; j++){
        if(A[k] > A[j] && D[k] < D[j] + 1)
          D[k] = D[j] + 1;
      }
    }
    result[i] = I[i] + D[i+1]-1;
  }
  return *max_element(result, result+n);
}
