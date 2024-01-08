#include<iostream>
using namespace std;

void Merge(int arr[], int l, int m, int r){

	int i, j, k;
	int n1 = m-l+1;
	int n2 = r-m;

	//creating temporary arrays
	int L[n1], R[n2];

	//copying elements of sub-arrays into temporary arrays
	for(i=0; i<n1; i++){
		L[i] = arr[l+i];
	}

	for(j=0; j<n2; j++){
		R[j] = arr[m+j+1];
	}

	//merging sorted arrays 
	i=0;
	j=0;
	k=l;

	//merging the sorted sub-arrays by overwriting the original array
	while(i<n1 && j<n2){

		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}

		else{
			arr[k] = R[j];
			j++;
		}

		k++;
	}

	//copying remaining elements

	while(i<n1){

		arr[k] = L[i];
		i++;
		k++;

	}

	while(j<n2){

		arr[k] = R[j];
		j++;
		k++;
	}

}

// l for left index and r for right index of the arrays

void MergeSort(int arr[], int l, int r){

	if(l<r){
		int m = (l+r-1)/2;

		MergeSort(arr, l, m);
		MergeSort(arr, m+1, r);

		Merge(arr, l, m, r);

	}
}

void printArray(int arr[], int n){

	for(int i=0; i<n; i++){

		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int main(){

	int arr[] = {5,7,3,8,11};

	int n = sizeof(arr)/sizeof(arr[0]);

	MergeSort(arr, 0, n-1);

	printArray(arr, n);

	return 0;
}
