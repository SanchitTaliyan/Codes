int recsum(vector<vector<int>> &A, int m, int n){
    int result = 0;
    int memo[1000][1000] = {0};
    if(memo[m][n] != 0)
        return memo[m][n];
    else if(m == 0 && n == 0){
        return A[0][0];
    }
    else if(m == 0 && n != 0){
        memo[m][n] = recsum(A, m, n-1) + A[m][n];
    }
    else if(m != 0 && n == 0){
        memo[m][n] = recsum(A, m-1, n) + A[m][n];
    }
    else memo[m][n] = min(recsum(A, m-1, n) + A[m][n], recsum(A, m, n-1) + A[m][n]);
    return memo[m][n];
}

int Solution::minPathSum(vector<vector<int> > &A) {
    int ans = recsum(A, A.size() - 1, A[0].size() - 1);
    return ans;
}
