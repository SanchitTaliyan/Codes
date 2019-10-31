int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
        int na = A.size();
        int nb = B.size();
        int nc = C.size();
        
        int minimize = abs(max( A[na-1], max(B[nb-1], C[nc-1])) - min(A[na-1], min(B[nb-1], C[nc-1])));
        
        int curr_diff = minimize;
        
        int maxTerm;
        
        while((na-1) != -1 && (nb-1) != -1 && (nc-1) != -1){
            
            curr_diff = abs(max( A[na-1], max(B[nb-1], C[nc-1])) - min(A[na-1], min(B[nb-1], C[nc-1])));
            
            if(curr_diff < minimize) minimize = curr_diff;
            
            maxTerm = max(A[na-1], max(B[nb-1], C[nc-1]));
            
            if(A[na-1] == maxTerm) na = na-1;
            
            else if(B[nb-1] == maxTerm) nb=nb-1;
            
                else nc=nc-1;
        }
        
        return minimize;
}
