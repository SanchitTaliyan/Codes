#include<iostream>
#include<string>
using namespace std;

int main(){

string S = "SanchiT";

reverse(S[1], S[4]);
int i = 0;
while(S[i]){

	cout<<S[i];
	i++;
}

cout<<endl;
return 0;

}