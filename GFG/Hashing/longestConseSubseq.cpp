#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <climits>
 
using namespace std;

int longestSequence(vector<int> arr, int N) {
    unordered_map<int, int> s;

    int minNum = INT_MAX;
    int maxNum = INT_MIN;

    for(int i = 0; i < N; i++) {
        if(s.find(arr[i]) != s.end()) {
            s[arr[i]]++;;
        }
        else {
            s[arr[i]] = 1;
        }
        minNum = min(minNum, arr[i]);
        maxNum = max(arr[i], maxNum);
    }

    //cout << "\n" << minNum << "\n";

    int currCount = 1;
    int maxCount = 1;

    for(int i = minNum + 1; i <= maxNum; i++) {
        if(s.find(i) != s.end()) {
            currCount++;
            maxCount = max(currCount, maxCount);
        }else {
            currCount = 0;
        }
    }

    return maxCount;
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

        int res = longestSequence(arr, N);
        cout << res << "\n";
    }
 
    return 0;
}