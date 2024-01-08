#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

int main(){

	vector<int> my = {1,5,2,4,3};

	vector<int> :: iterator ptr;

	for(ptr = my.begin(); ptr<my.end(); ptr++){

		cout<<*ptr<<",";
	}

	cout<<endl;

	return 0;
}