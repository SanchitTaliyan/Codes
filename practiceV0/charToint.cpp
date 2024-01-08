#include<iostream>
#include<vector>
using namespace std;

int main(){

	vector<char> v;
	string A = "43";

	int i = 0;

	v.push_back(A[i]);
	v.push_back(A[i+1]);

	int temp;

	temp = (int)(v[i])-48;

	cout<<temp<<"\n";
	return 0;
}