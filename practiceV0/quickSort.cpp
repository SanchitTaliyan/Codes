#include<iostream>
using namespace std;

void swap (int* a, int* b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){

	// we are picking last element as pivot
	int pivot = arr[high];

	// initializing variable to mark index of smaller elements

	int i = low-1;

	if(high>low){

	for(int j=low; j<=high; j++){

		if(arr[j]<=pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
}
	return i;
}
// partition function is completed

void quickSort(int arr[], int low, int high){

	if(low<high){

		int pi = partition(arr, low, high);

		quickSort(arr, low, pi-1);  //before pi
		quickSort(arr, pi+1, high);  //after pi


	}
}

void printArray(int arr[], int n){

	for(int i=0; i<n; i++){

		cout<<arr[i]<<" ";

	}
	cout<<endl;
}

int main() {

	int arr[] = {2,5,3,9,11,4,14};

	int n = sizeof(arr)/sizeof(arr[0]);

	quickSort(arr, 0, n-1);

	printArray(arr, n);

	return 0;

}





