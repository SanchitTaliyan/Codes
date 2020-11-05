#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <unordered_set>
 
using namespace std;

void pairWithSum(vector<int> a, int n, vector<int> b, int m, int k) {
    unordered_set<int> s;
    set<pair <int, int> > res;

    sort(a.begin(), a.end());

    for(int i = 0; i < m; i++) {
        s.insert(b[i]);
    }

    int flag = 0;
    for(int i = 0; i < n; i++) {
        if(s.find(k - a[i]) != s.end()) {
            if(flag != 0) {
                cout << ", ";
            }
            cout << a[i] << " " << k - a[i];
            flag++;
        }
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int n, m ,k;
        cin >> n >> m >> k;

        vector<int> arr1(n);
        vector<int> arr2(m);

        for(int j = 0; j < n; j++) {
            cin >> arr1[j];
        }

        for(int j = 0; j < m; j++) {
            cin >> arr2[j];
        }

        pairWithSum(arr1, n, arr2, m, k);
    }
 
    return 0;
}