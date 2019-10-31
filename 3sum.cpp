int Solution::threeSumClosest(vector<int> &A, int B) {
    
    int size = A.size();
    vector<int> a = A;
    int curr_sum = 0;
    int near_dif = INT_MAX;
    int l , r;
    int diff = 0;
    sort(a.begin(), a.end());
    int ans;
    for(int i = 0; i<size-2; i++){
        l = i+1;
        r = size-1;
        while(l<r){
            curr_sum = a[i]+a[l]+a[r];
            diff  = abs(B-curr_sum);
            if(curr_sum == B) return curr_sum;
            
            if(curr_sum < B){
                l++;
            }
            if(curr_sum > B){
                r--;
            }
            if(diff<=near_dif){
                near_dif = diff;
                ans  = curr_sum;
            }
        }
        
    }
    
    return ans;
}
