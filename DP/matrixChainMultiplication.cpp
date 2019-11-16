#include<iostream>
#include<vector>

using namespace std;


int matrixChainMultiplication(vector<int> &arr, int n) {

  vector<vector<int>> mul(n, vector<int>(n, 0));
  int count;

  for(int L = 2; L < n; L++) {

    for(int i = 1; i < n - L + 1; i++) {

      int j = i + L - 1;
      mul[i][j] = INT_MAX;

      for(int k = i; k < j; k++) {
        count = mul[i][k] + mul[k + 1][j] + arr[i-1] * arr[k] * arr[j];

        if(count < mul[i][j]) mul[i][j] = count;
      }
    }

  }

  return mul[1][n-1];

  // recursive idea
  // if(i == j) return 0;
  //a
  // int count, min = INT_MAX;
  //
  // for(int k = i; k < j; k++) {
  //   count = matrixChainMultiplication(arr, i, k) + matrixChainMultiplication(arr, k +1, j) + arr[i-1] * arr[k] * arr[j];
  //
  //   if(min > count) min = count;
  // }
  // return min;
}

int main() {
  vector<int> arr {1, 2, 3, 4, 3};
  int n = arr.size();
  cout << matrixChainMultiplication(arr, n);

  return 0;
}
