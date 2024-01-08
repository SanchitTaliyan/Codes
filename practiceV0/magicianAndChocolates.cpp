#include<iostream>
#include<vector>

using namespace std;
int solution(vector<int> &A, int K){
  priority_queue<int> pq(A.begin(), A.end());
  int total = 0;
  while(k){
    int top = pq.top();
    pq.pop();
    pq.push(top/2);
    total += top;
    k--
  }
  return total;
}
