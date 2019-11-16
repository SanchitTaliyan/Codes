#include <bits/stdc++.h>
using namespace std;

int minPalindromePartition(string s) {
    int n = s.length();
    vector<vector<bool>> P(n, vector<bool>(n));
    vector<int> count(n, INT_MAX);
    for(int i = 0; i < n; i++) {
        P[i][i] = true;
    }

    for(int L = 2; L <= n; L++) {
        for(int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;

            if(L == 2) P[i][j] = (s[i] == s[j]);

            else
                P[i][j] = (s[i] == s[j]) && P[i+1][j-1];
        }
    }

    for(int i = 0; i < n; i++) {
        if(P[0][i]) count[i] = 0;

        else
            for(int j = 0; j < i; j++) {
                if(P[j+1][i] && count[j] + 1 < count[i])
                    count[i] = count[j] + 1;
            }
    }
    return count[n-1];
}

int main() {
	//code

	int T;
	cin>>T;

	for(int i = 0; i < T; i++) {
	    string s;
	    cin>>s;

	    cout << minPalindromePartition(s)<< endl;
	}
	return 0;
}
