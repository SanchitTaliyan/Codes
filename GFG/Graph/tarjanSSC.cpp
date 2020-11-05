#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <stack>

using namespace std;

int v = 8;
vector<int> ids(v, -1);
vector<int> low(v);
stack<int> s;
int ssc = 0;
vector<bool> onStack(v, false);
int id = 0;

void printVec(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << i << ": " << vec[i] << "\n";
    }
}

void dfs(int at, vector< vector<int> > adj) {
    s.push(at);
    onStack[at] = true;
    ids[at] = id;
    low[at] = id;

    id++;
    for(int to: adj[at]) {
        if(ids[to] == -1) {
            dfs(to, adj);
        }

        if(onStack[to]) {
            low[at] = min(low[at], low[to]);
        }
    }

    if(ids[at] == low[at]) {
        int node;
        
        while(1) {
            node = s.top();
            s.pop();
            low[node] = ids[at];
            onStack[node] = false;
            if(node == at) break;
        }
        ssc++;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    vector< vector<int> > adj(v);

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[3].push_back(4);
    adj[3].push_back(7);
    adj[4].push_back(5);
    adj[5].push_back(0);
    adj[5].push_back(6);
    adj[6].push_back(0);
    adj[6].push_back(2);
    adj[6].push_back(4);
    adj[7].push_back(5);
    adj[7].push_back(3);

    for(int i = 0; i < v; i++) {
        if(ids[i] == -1) {
            dfs(i, adj);
        }
    }
    cout << ssc << "\n";
    printVec(low);

    return 0;
}

























