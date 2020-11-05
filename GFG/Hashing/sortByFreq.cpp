#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }

    return a.second > b.second;
}

vector<int> sorted(vector<int> arr, int n) {
    unordered_map<int, int> map;
    vector<int> res;
    vector<pair <int, int> > v;

    for(int i = 0; i < n; i++) {
        if(map.find(arr[i]) != map.end()) {
            map[arr[i]] ++;
        }

        else {
            map[arr[i]] = 1;
        }
    }

    copy(map.begin(), map.end(), back_inserter(v));

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < v.size(); i++) {
        while(v[i].second --) {
            res.push_back(v[i].first);
        }
    }

    return res;
}

void printArr(vector<int> &vec, int n) {
    for(int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int n;
        cin >> n;

        vector<int> arr(n);
        
        for(int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        vector<int> res = sorted(arr, n);

        printArr(res, res.size());
        cout << endl;
    }
    return 0;
}