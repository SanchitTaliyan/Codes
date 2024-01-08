vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    int size = A.size();
    // set<int> c;
    // for(int i=0;i<A.size();i++)
    // {
    //     c.insert(A[i]);
    // }
    // A.clear();
    // for(auto i=c.begin();i!=c.end();i++)
    // {
    //     A.push_back(*i);
    // }
    sort(A.begin(),A.end());
    int l , r;
    int sum = 0;
    vector<vector<int> >ans;
    int k = 0;
    // for(auto i:A) cout<<i<<' ';
    for(int i = 0; i<size-2;){
        int prev=A[i];
        l = i+1;
        r = size-1;
        
        vector<int> temp;
        while(l<r){
            
            sum = A[i]+A[l]+A[r];
            
            if(sum < 0) l++;
            
            if(sum>0) r--;
            
            if(sum == 0){
                
                temp.push_back(A[i]);  
                temp.push_back(A[l]);
                temp.push_back(A[r]);
                k++;
                int tem=A[l];
                while(l<r && A[++l]==tem);
                ans.push_back(temp);
                temp.clear();
                
            }
        }
    // cout<<endl;    
    while(i<size-2 && A[++i]==prev);
    }
    
    return ans;
}
