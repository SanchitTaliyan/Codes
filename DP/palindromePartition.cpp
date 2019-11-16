#include <bits/stdc++.h>
using namespace std;

int palindrome(string &s, int i, int j) {
    int l = i;
    int h = j;

    while(l < h) {
        if(s[l] != s[h]) return 0;

        l ++;
        h --;
    }

    return 1;
}

string convert(int a, int b) {
    return to_string(a) + "" + to_string(b);
}

int minPalindromePartition(string &s, int i, int j, unordered_map<string, int> &memo) {

    if(i > j) return 0;
    string ij = convert(i, j);

    if(memo.find(ij) != memo.end()) return memo[ij];

    if(i == j){
     memo[ij] = 0;
     return 0;
    }

    if(palindrome(s, i, j)){
        memo[ij] = 0;
        return 0;
    }

    int mini = INT_MAX;

    for(int k = i; k < j; k++) {
        int left = INT_MAX;
        int right = INT_MAX;

        if(memo.find(convert(i, k)) != memo.end()) left = memo[convert(i, k)];

        if(memo.find(convert(k + 1, j)) != memo.end()) right = memo[convert(k + 1, j)];

        if(left == INT_MAX) {
            left = minPalindromePartition(s, i, k, memo);
        }

        if(right == INT_MAX) {
            right = minPalindromePartition(s, k + 1, j, memo);
        }

        mini = min(mini, left + right + 1);
    }

    memo[ij] = mini;
    return memo[ij];
}

int main() {
	//code

	int T;
	cin>>T;

	for(int i = 0; i < T; i++) {
	    string s;
	    cin>>s;

	    unordered_map<string, int> memo;
	    cout << minPalindromePartition(s, 0, s.length() - 1, memo)<< endl;
	}
	return 0;
}
