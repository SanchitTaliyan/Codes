vector<vector<int> > Solution::generate(int A) {
    
    vector<vector <int > > v(A);
    
    v[0].push_back(1);
    
    for(int j=1; j<A; j++){
        v[j].push_back(1);
        for(int k = 1; k<j; k++){
        
         v[j].push_back(v[j-1][k], v[j-1][k-1]);

        }

        v[j].push_back(1);
    }
    
    
    return v;    
    
}