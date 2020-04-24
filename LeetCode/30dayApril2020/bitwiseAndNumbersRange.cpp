#include<iostream>

using namespace std;

class Solution {
public:
    
    int msb(int n) {
        int msbP = -1;
        
        while(n) {
            n = n >> 1;
            
            msbP++;
        }
        
        return msbP;
    }
    
    int rangeBitwiseAnd(int m, int n) {
//         int result = 0;
//         while(m && n) {
//             int msbM = msb(m);
//             int msbN = msb(n);
        
//             if(msbM != msbN) break;
            
//             int msbVal = (1 << msbM);
            
//             result += msbVal;
            
//             m = m - msbVal;
//             n = n- msbVal;
//         }
        
//         return result;
        
        while(m < n){
            n = n & (n - 1); // we can also write n -= (n & -n);
        }
        return n;
        
    }
};