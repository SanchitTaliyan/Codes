int maxArea(vector<vector<bool>> &A){
  int R = A.size();
  int C = A[0].size();

  int his[R+1][C+1];
  for(int i = 0; i<C; i++){
    his[0][i] = A[0][i];
    for(int j = 1; j<R; j++){
      if(A[j][i] == 0)
        his[j][i] = 0;
      else   his[j][i] = his[j-1][i] + 1;
    }
  }

  for(int i = 0; i<R; i++){
    int col = 0;
    vector<int> count(R+1, 0);
    for(int j = 0; j<C; j++){
      count[his[i][j]]++;
    }
    for(int k = R; k>=0; k--){
      if(count[k]>0){
        for(int j = 0; j<count[k]; j++){
          his[i][col] = k;
          col++;
        }
      }
    }
  }

  int curr_area, max_area = 0;
  for(int i = 0; i<R; i++){
    for(int j = 0; j<C; j++){
      curr_area = (j+1) * his[i][j];
      if(max_area<curr_area)
        max_area = curr_area;
    }
  }
  return max_area;
}
