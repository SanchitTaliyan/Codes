int min(int a, int b, int c){
  return (min(a, min(b,c)));
}

int editDistance(string A, string B, int m, int n){
    vector<vector<int>> sol(m, vector<int>(n, 0));
    for(int i = 0; i<sol.size(); i++){
      for(int j = 0; j<sol[0].size(); j++){
        if(i == 0)
          sol[i][j] = j;
        if(j == 0)
          sol[i][j] = i;
        }
      }

    for(int i = 1; i<sol.size(); i++){
      for(int j = 1; j<sol[0].size(); j++){
        if(A[i-1] == B[i-1])
          sol[i][j] = sol[i-1][j-1];
        else
          sol[i][j] = 1 + min(sol[i-1][j-1], sol[i-1][j], sol[i][j-1]);
      }
    }
    return sol[m-1][n-1];
}
