#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
 
#define inf 10000000;

using namespace std;

vector< vector<int> > floydWarshall(int V, vector< vector<int> > adj) {
    vector< vector<int> > dp(V, vector<int>(V));

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            dp[i][j] = adj[i][j];
        }
    }

    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    return dp;
}

void printGraph(int V, vector <vector<int> > ans) {
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(ans[i][j] == 10000000) {
                cout << "INF ";
            }else {
                cout << ans[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int v;
        cin >> v;

        vector< vector<int> > adj(v, vector<int> (v));

        for(int u = 0; u < v; u++) {
            for(int k = 0; k < v; k++) {
                string s;
                cin >> s;

                if(s == "INF") {
                    adj[u][k] = inf;
                }

                else {
                    adj[u][k] = stoi(s);
                }
            }
        }

        vector <vector<int> > ans = floydWarshall(v, adj);
        printGraph(v, ans);
    }
 
    return 0;
}