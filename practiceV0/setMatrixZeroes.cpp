void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > v;
    
    int m = A.size();
    int n = A[0].size();
    int k = 0;
    
    for(int i = 0; i<m; i++){
        
        for(int j =0; j<n; j++){
            
            if(A[i][j] == 0){
                v[k].push_back(i);
                v[k].push_back(j);
                k++;
            }
        }
    }
    
    int len  = v.size()-1;
    int c = 0;
    
    while(c<=len){
        
        for(int j = 0; j<n; j++){
            A[v[c][0]][j] = 0;
        }
        
        for(int i =0; i<m; i++){
            
            A[i][v[c][1]] = 0;
        }
        c++;
    }
    
    
}
