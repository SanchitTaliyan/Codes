#include<iostream>
#include<vector>
using namespace std;

//void printArray(vector<int> &A, int n){
	//for(int i=0; i<n; i++)
	//	cout<<A[i]<<" ";
	//cout<<endl;
//}


int main(){

	int arr[] = {2,3,4,5,6};
	std::vector<int> A(arr, arr+5);

	int n = A.size();

	cout<<n<<endl;

	//A.insert(A.end(), arr, arr+5);

	cout<<A[2];
	return 0;
}