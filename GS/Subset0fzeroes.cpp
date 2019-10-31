#include<iostream>
using namespace std;

int getSubsets(int k, int n, vector<int> arr){
  int max = INT_MIN;
  int sum = 0;
  int result = 1;
  int n = 0;
  int r = 0;

  for(int i = 0; i<n; i++){
    if(max<arr[i])
      max = arr[i];
  }
  vector<int> prime(max+1, INT_MAX);
  prime[0] = 0;
  prime[1] = 0;
  for(int i = 2; i<=max; i++){
    if(prime[i] == INT_MAX){
      for(int j = i; j<=N; j += i){
        prime[j] = min(prime[j], i);
      }
    }
  }
  for(int i = 0; i < n; i++){
    int a = arr[i];
    while(a != 1){
      sum += prime[a];
      while(a%prime[a]==0) a /= prime[a];
    }
  }
  r = k - 1;
  n = sum + r;
  if(r > n-r)
    r = n - r;
  for(int i = 0; i<r; i++){
    result *= (n-i);
    result /= (i+1);
  }
  return result;
}
