#include <cmath>
#include <sstream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;

    cout<<s[3];
    /*stringstream ss;
    ss << s;
    cout<<ss<<"this is ss:"<<endl;
    
    string temp;
    int found;
    int sum = 0;
    while(!ss.eof()){
        ss >> temp;  //extracting word by word
        if(stringstream(temp) >> found){
            cout<<found<<endl;
            sum = sum + found;
        }
        temp = " ";
    }

    cout<<sum;*/
    return 0;
}
