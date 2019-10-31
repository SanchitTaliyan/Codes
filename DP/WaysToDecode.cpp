int fib(int n){
    int memo[1000];
    if(n<=1){
        return 1;
    }
    if(memo[n] != 0) return memo[n];

    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int Solution::numDecodings(string A) {
    int n = A.length();
    string comp;
    int numzero = 0;
    int count = 0;
    if(n==1){
        return n;
    }
    if(A.substr(0,1)=="0") return 0;
    if(n == 2){
        comp = "";
        comp = A.substr(0,2);
        //cout<<comp;
        if(comp>"26" || A.substr(n-1, 1) == "0"){
            return n-1;
        }
        else
            return n;
    }
    for(int i = 0; i < n-1; i++){
        comp = "";
        if(A[i] == '0'){
            if(A.substr(i-1, 2)>"20") return 0;
            else;
                numzero++;
        }
        comp = A.substr(i,2);
        //cout<<(comp);
        if(comp > "26")
            count++;
    }
    if(A.substr(n-1, 1) == "0")
        numzero++;

    int result = fib(n) - count-numzero;
    return result;
}
