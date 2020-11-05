#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
 
using namespace std;
 
int countZeroSubArr(vector<int> arr, int N) {
    unordered_map<int, int> map;
    int zero = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += arr[i];
        if(sum == 0){
            zero++;
            //continue;
        }

        if(map.find(sum) != map.end()) {
            map[sum]++;
        }
        else {
            map[sum] = 1;
        }
    }

    int res = zero;
    //cout <<"*****" << zero << "*******";

    for(auto it = map.begin(); it != map.end(); it++) {
        int num = it->second;

        //cout << it->first << " " << it->second << " \n";
        res += ((num) * (num - 1))/2;
    }

    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;

        vector<int> arr(N);

        for(int j = 0; j < N; j++) {
            cin >> arr[j];
        }

        //cout << endl;

        int res = countZeroSubArr(arr, N);

        cout << res << "\n";
    }
 
    return 0;
}