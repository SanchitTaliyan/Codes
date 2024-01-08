#include<iostream>
#include<string>
using namespace std;

void print(char* C){
	int i = 0;
	while(C[i] != '\0'){
		cout<<C[i];
		i++;
	}
	cout<<"\n";
}

int main(){

	char C[20] = "HELLO";
	print(C);

	return 0;
}
