#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void printSet(set< pair<pair<int, int>, pair<int, int> > > s) {
    for(auto it = s.begin(); it != s.end(); it++) {
        cout << it->first.first << " " << it->first.second << " " << it->second.first << " " << it->second.second << " $";
    }
    cout << "\n";
}

void getQuadruple(vector<int> arr, int n, int k) {
    unordered_map< int, vector< pair<int, int> > > map; // to store all pair sum and pair (i, j)
    int sum;
    set< pair< pair<int, int>, pair<int, int> > > s;

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            sum = arr[i] + arr[j];
            
            if(map.find(k - sum) != map.end()) {                  // if we found k - sum in the hash map
                auto it = map.find(k - sum);                      // get iterator to it
                vector< pair<int, int> > temp = it->second;       // get all the pair index for the given pair k - sum 

                for(int k = 0; k < temp.size(); k++) {
                    // check for intersection in four index
                    if(i != temp[k].first && j != temp[k].first && i != temp[k].second && j != temp[k].second) {
                        
                        vector<int> res;
                        res.push_back(arr[i]);
                        res.push_back(arr[j]);
                        res.push_back(arr[temp[k].first]);
                        res.push_back(arr[temp[k].second]);
                        sort(res.begin(), res.end());

                        pair<int, int> p1 = make_pair(res[0], res[1]);
                        pair<int, int> p2 = make_pair(res[2], res[3]);

                        s.insert(make_pair(p1, p2));
                    }
                }
            }

            map[sum].push_back(make_pair(i, j));
        }
    }

    if(s.size() > 0) {
        printSet(s);
    }
    else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);

        for(int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        getQuadruple(arr, n, k);
    }
    return 0;
}