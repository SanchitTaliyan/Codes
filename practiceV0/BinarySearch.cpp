#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int BinarySearch(vector<int> &A, int n, int target){

	int start = 0, end = n-1;
	while(start<=end){

		int mid = start + (end-start)/2;

		if(target == A[mid]){
			return mid;
		}

		else if(target > A[mid]){
			start = mid+1; 
		}
		else end = mid -1;

	}
	return -1;
}

int main(){

	int a[] = { 1,2,4,6,8,11,15,10 };
	int l  = sizeof(a)/sizeof(a[0]);
	vector<int> A(a, a+l);
	int n = A.size();
	sort(A.begin(), A.end());
	int x;
	cout<<"enter the no. x to be searched"<<endl;
	cin>>x;
	int index = BinarySearch(A, n, x);
	if(index != -1){
		cout<<"no. "<<x<<" is present at index "<<index<<" in the vector"<<endl;
	}

	else cout<<"no. is not present in the vector list"<<endl;

}