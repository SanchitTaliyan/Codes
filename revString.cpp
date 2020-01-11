#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

	string S = "SanchiT";

	reverse(S.begin(), S.end());
	int i = 0;
	while(S[i]){
		cout<<S[i];
		i++;
	}

	cout<<endl;
	return 0;

}