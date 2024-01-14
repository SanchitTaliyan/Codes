#include <bits/stdc++.h>
using namespace std;

int minPlatforms(vector<int> arr, vector<int> dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int platforms = INT_MIN;
    int n = arr.size();
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < n) {
        if(arr[i] < dep[j]) {
            count++;
            platforms = max(platforms, count);`
            i++;
        }else {
            count--;
            j++;
        }
    }
    
    return platforms;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int n;
    cin >> n;
    vector<int> arrivals(n);
    vector<int> departures(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arrivals[i];
        cin >> departures[i];
    }
    
    cout << minPlatforms(arrivals, departures);
    return 0;
}
