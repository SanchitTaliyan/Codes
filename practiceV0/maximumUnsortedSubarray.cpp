vector<int> Solution::subUnsort(vector<int> &A) {
    
    vector<int> v = A;
    
    sort(v.begin(),v.end());
    
    int len  = v.size();
    vector<int> result;
    
    for(int i =0; i<len ; i++){
        
        if(v[i] != A[i]) result.push_back(i);
        
    }
    
    int k = result.size();
    
    vector<int> final;
    
    int n = result[0];
    int m = result[k-1];
    
    while(n<=m){
        
        final.push_back(n);
        n = n+1;
        
    }
    
    return final;
}
