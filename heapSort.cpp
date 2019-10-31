#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int> &A, int n, int i){
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if(l<n && A[l] > A[largest])
    largest = l;
  if(r<n && A[r] > A[largest])
    largest = r;
  if(largest != i){
    swap(A[i], A[largest]);
    heapify(A, n, largest);
  }
}

void heapSort(vector<int> &A){
  int n = A.size();
  for(int i = n/2-1; i>=0; i--){
    heapify(A, n, i);
  }
  for(int i = n-1; i>=0; i--){
    swap(A[0], A[i]);
    heapify(A, i, 0);
  }
}

void printVector(vector<int> A){
  for(int i = 0; i<A.size(); i++){
    cout<<A[i]<<" ";
  }
}

int main(){
  int arr[] = { 11, 2, 9, 13, 57, 25, 17, 1, 90, 3 };
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<int> A(arr, arr+n);
  heapSort(A);
  printVector(A);
  return 0;
}
