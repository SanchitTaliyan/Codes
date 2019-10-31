#include<iostream>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

bool checkTriplet(vector<int> &A, int n){
  unordered_map<int, int> hash;
  for(int i = 0; i<n; i++){
    if(hash.find[A[i]] != hash.end()){
      hash[A[i]]++;
    }
    hash[A[i]] = 1;
  }

  unordered_map<int, int> :: iterator itr;
  for(itr = hash.begin(), hash.end())
}
