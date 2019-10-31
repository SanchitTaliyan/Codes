#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int getMid(int s, int e) {return (s+(e-s)/2);}

//st pointer to segment tree
//si index of current node of segment tree
//ss starting index of segment node
//se end index of segment node
//qs start index of query
//qe end index of query
//Range minimum query util function

int RMQUtil(int *st, int ss, int se, int qs, int qe, int si){
  if(ss>=qs && se<=qe)
    return st[si];
  if(qe<ss || qs>se)
    return INT_MAX;
  int mid = getMid(ss, se);
  return min(RMQUtil(st, ss, mid, qs, qe, 2*si+1), RMQUtil(st, mid+1, se, qs, qe, 2*si+2));
}

int RMQ(vector<int> v, int n, int *st,int  qs,int qe){
  if(qs<0 || qe > n-1 || qs>qe)
    return -1;
  return RMQUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(vector<int> &A, int ss, int se, int *st, int si){
  if(ss == se){
    st[si] = A[ss];
    return A[ss];
  }
  int mid = getMid(ss, se);

  st[si] =  min(constructSTUtil(A, ss, mid, st, 2*si+1) , constructSTUtil(A, mid+1, se, st, 2*si+2));
  return st[si];
}

int *constructSt(vector<int> &A, int n){
  int x = int (ceil(log2(n)));
  int maxSize = 2*pow(2, x) - 1;

  int *st = new int[maxSize];

  constructSTUtil(A, 0, n-1, st, 0);
  return st;
}

int main(){
  int arr[] = {6,5,4,3,2,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<int> v(arr, arr+n);
  int min;
  int *st = constructSt(v, v.size());
  min= RMQ(v, v.size(), st, 1, 4);
  cout<<"Min from index 1 to 4 is the following: "<<min<<endl;
  return 0;
}
