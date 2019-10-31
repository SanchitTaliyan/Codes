#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){

	int A = 11;

	 vector<bool> v(A+1, true);
    v[0] = false;
    v[1] = false;
    
    for(int i = 2; i<=sqrt(A); i++){
        
        if(v[i] == true){
            
            for(int j = 2; i*j<=A; j++)
            v[i*j] = false;
        
            
        }
    }

    for(int i = 0; i<v.size(); i++){

    	cout<<i<<" is prime"<<v[i]<<endl;
    }


    return 0;

}