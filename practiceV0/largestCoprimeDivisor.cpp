
int gcd(int a, int b){
    
    int temp;
    int j = a;
    int l = b;
    
    if(j == l) return j;
    
    if(j>l){
        
        while(l>0){
            
            temp = l;
            l = j%temp;
            j = temp;
            if(l == 0) return j;
            
        }
    }
    
    else{
        
        while(j>0){
            
            temp = j;
            j = l%temp;
            l = temp;
            if(j == 0) return l;
        }
    }
}


int Solution::cpFact(int A, int B) {
    int g = sqrt(A);
    for(int i =A; i>=g; i--){
        
        int k = gcd(i, B);
        
        if(A%i == 0 && k == 1){
            
            return i;
            break ;
        } 
        
    }
    
}
