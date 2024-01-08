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

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si){
  if(ss>=qs && se<=qe)
    return st[si];
  if(ss>qe || se<qs)
    return 0;
  int mid = getMid(ss, se);
  return getSumUtil(st,ss, mid, qs, qe, 2*si+1) + getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si){
  if(i<ss || i>se){
    cout<<"Invalid Input\n";
    return;
}

  st[si] += diff;
  if(se != ss){
    int mid = getMid(ss, se);
    updateValueUtil(st, ss, mid, i, diff, 2*si+1);
    updateValueUtil(st, ss, mid , i ,diff, 2*si+2);
  }
}

void updateValue(vector<int> &A, int *st, int n, int i , int newVal){
  if(i<0 || i>n-1)
    return;
  int diff = newVal - A[i];
  A[i] = newVal;

  updateValueUtil(st, 0, n-1, i, diff, 0);
}

int getSum(int *st, int n, int qs, int qe){
  if(qs<0 || qs>n-1 || qs>qe){
    cout<<"Invalid Input\n";
    return -1;
  }
  return getSumUtil(st, 0, n-1, qs, qe, 0);
}
int constructSTUtil(vector<int> &A, int ss, int se, int *st, int si){
  if(ss == se){
    st[si] = A[ss];
    return A[ss];
  }
  int mid = getMid(ss, se);

  st[si] =  constructSTUtil(A, ss, mid, st, 2*si+1) + constructSTUtil(A, mid+1, se, st, 2*si+2);
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
  int arr[] = {1,2,3,4,5,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<int> v(arr, arr+n);
  int sum;
  int *st = constructSt(v, v.size());
  sum = getSum(st, v.size(), 2, 5);
  cout<<"Sum from index 2 to 5 is the following: "<<sum<<endl;
  updateValue(v, st, v.size(), 2, 5);
  sum = getSum(st, v.size(), 2, 5);
  cout<<"After update of 2(from 3 to 5) sum from index 2 to 5 is the following: "<<sum;
  return 0;
}
