#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> maxone(vector<int> &A, int B) {
    
    int n = A.size();
    int M = B;
    int count = 0;
    int max = 0;
    int i = 0;
    int k;
    int index;
    while(i>=0 && i<n){
        
        if (A[i] == 1) {
            count++;
            i++;
        }
            if(A[i] == 0 && M>0){
                if(M==B){
                    index = i;
                }
                count++;
                M--;
                i++;
            }
        
        if(M == 0 && A[i] == 0){
            if(max<=count){
                max = count;
                int k = i-1;
            }
            count = 0;
            i = index + 1;
            M = B;
        }
    }
    
    vector<int>ans;
    int p = 0;
    for(int j = 0 ; j<max; j++){
        p = k-max+1+j;
        ans.push_back(p);
    }
    
    return ans;
}


int main(){

    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);

    int k = maxone(v, 1);

    cout<<k<<endl;

    return 0;
}