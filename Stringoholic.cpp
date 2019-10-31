#define mod 1000000007
int Solution::solve(vector<string> &A) {
    int l = 1,len=A.size(),h;
    vector<int>v(len);
    for(int k=0;k<len;k++){
        //  saving time interval t for each string
    int n = A[k].length();
    if(n<=1){
       v[k] = 1;
    }
    else{
        long long i=1,changes=0;
        while(1){
            changes = (i*(i+1))/2;
          if(changes%n==0){
              v[k]=i;
              break;
          }
            i++;
        }
     }

    }
    long long ans=1;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len && v[i]!=1 ;j++){

            v[j] = v[j]/__gcd(v[j],v[i]);
        }
        ans = 1ll*(ans%mod*(v[i])%mod)%mod;
    }
 return ans%mod;
}
