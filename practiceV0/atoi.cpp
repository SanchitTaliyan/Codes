#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int ato(const string A) {
    vector<char> v;
    int j = 0;
    //int sign = 1;
    while(A[j] == ' '){
        j++;
    }
    int i = j;
    //if(A[i] == '-')
    while(A[i]){
       /* if(A[i] == ' '){
            i++;
            continue;
        }
        */
        //if(A[i] =='0' || A[i] == '1' || A[i] == '2' || A[i] == '3' || A[i] == '4' || A[i] == '5' || A[i] == '6' || A[i] == '7' || A[i] == '8' || A[i] == '9'){
        if(A[i]>='0'&& A[i]<='9') {  
            v.push_back(A[i]);
        }
        else break;
            i++;
    }
    int n = v.size(), p;
    int ans = 0;
    int temp;
    for(int j = 0; j<n; j++){
        p = n-1-j;
        temp = (int)(v[j])-48;
        ans = ans + temp*pow(10, p);
    }
    return ans;
}

int main(){

string s = " 43 675";
int j = ato(s);

cout<<j<<endl;

}
