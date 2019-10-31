#include<iostream>
#include<vector>
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}


int partition(vector<int> &A, int l, int h){


	int pivot, i;
	int j = l-1;
	pivot = A[h];

	if(h>l){
		for(i=l; i<=h; i++){

			if(A[i] <= pivot){

				j++;
				swap(&A[j], &A[i]);
			}
		}

	}

	return j;

}


void quickSort(vector<int>&A, int l, int h){

	if(l<h){
		int p = partition(A, l, h);

		quickSort(A, l, p-1);
		quickSort(A, p+1, h);
	}

}

void printArray(vector<int> &A, int n){
	for(int i = 0; i < n; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main(){

	int arr[] = {2,5,13,11,7,9};

	vector<int> A(arr, arr+6);

	int n = A.size();

	quickSort(A, 0, n-1);
	printArray(A, n);

	return 0;
}









