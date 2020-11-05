#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
 
using namespace std;

int v = 9;
vector<int> ids(v);
vector<int> low(v);
vector<bool> articulationPoints(v, false);

void dfs(int root, int at, int parent, int id, int &noOfOut, vector<bool> &visited, vector< vector<int> > edges) {
    visited[at] = true;
    ids[at] = id;
    low[at] = id;
    id++;
    if(parent == root) noOfOut++;

    for(int to: edges[at]) {
        if(!visited[to]) {
            dfs(root, to, at, id, noOfOut, visited, edges);
            low[at] = min(low[at], low[to]);
            if(ids[at] < low[to])
                articulationPoints[at] = true;
            
            if(ids[at] == low[to])
                articulationPoints[at] = true;
        }
        else {
            low[at] = min(low[at], ids[to]);
        }
    }
}

void printVec(vector<bool> vec) {
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i]) cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    vector< vector<int> > edges(v);
    vector<bool> visited(v, false);
    int id = 0;
    int noOfOut = 0;

    edges[0].push_back(1);
    edges[0].push_back(2);
    edges[1].push_back(2);
    edges[1].push_back(0);
    edges[2].push_back(0);
    edges[2].push_back(1);
    edges[2].push_back(3);
    edges[2].push_back(5);
    edges[3].push_back(2);
    edges[3].push_back(4);
    edges[4].push_back(3);
    edges[5].push_back(2);
    edges[5].push_back(6);
    edges[5].push_back(8);
    edges[6].push_back(5);
    edges[6].push_back(7);
    edges[7].push_back(6);
    edges[7].push_back(8);
    edges[8].push_back(7);
    edges[8].push_back(5);

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            noOfOut = 0;
            dfs(i, i, -1, id, noOfOut, visited, edges);
            if(noOfOut > 1)
                articulationPoints[i] = true;
        }
    }

    printVec(articulationPoints);
    return 0;
}