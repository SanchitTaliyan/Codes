#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){   //defining insertion sort by recurssion

	if(n<=1)       // base case empty array
		return;

	insertionSort(arr, n-1);          //recurssive call it is important to put it here.

	int last ,j, i;

	last = arr[n-1];                 //last element is sorted in every call. That's why array is decreased by one in every call.
	j = n-2;

	while(j>=0 && arr[j] > last){        //sorting of last element in the sorted array

		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = last;

}

void printArray(int arr[], int n){

	for(int i=0; i < n; i++)
		cout<<arr[i]<<" ";
}


int main(){

	int arr[] = {4,8,23,9,1,8};

	int n = sizeof(arr)/sizeof(arr[0]);

	insertionSort(arr, n);

	printArray(arr, n);

	return 0;
}