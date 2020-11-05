#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <unordered_set>
 
using namespace std;

bool isSubArr(vector<int> arr1, int n, vector<int> arr2, int m) {
    unordered_set<int> s;

    for(int i = 0; i < n; i++) {
        s.insert(arr1[i]);
    }

    for(int i = 0; i < m; i++) {
        if(s.find(arr2[i]) == s.end()) {
            return false;
        }
    }

    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int n, m;
        cin >> n >> m;

        vector<int> arr1(n);
        vector<int> arr2(m);

        for(int i = 0; i < n; i++) {
            cin >> arr1[i];
        }

        for(int i = 0; i < m; i++) {
            cin >> arr2[i];
        }

        bool res = isSubArr(arr1, n, arr2, m);
        
        if(res) {
            cout << "Yes";
        }else {
            cout << "No";
        }
        cout << "\n";
    }
 
    return 0;
}