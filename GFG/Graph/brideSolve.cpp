#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
/*
class Edge {
    private:
    int to, from;

    public:
        Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
        }
};
*/
using namespace std;

vector<int> ids(9, 0);   // here we will store ids of the nodes
vector<int> low(9, 0);  // here we will store the lowLink value of all the nodes

void bridgeSolve(int at, vector < vector<int> > edges, vector<bool> &visited, int parent, int id, vector<int> &bridges) {
    visited[at] = true;
    id = id + 1;
    ids[at] = id;
    low[at] = id;
    

    for(int to: edges[at]) {

        if(to == parent) continue;

        if(!visited[to]) {
            bridgeSolve(to, edges, visited, at, id, bridges);
            low[at] = min(low[at], low[to]);
            if(ids[at] < low[to]) {
                bridges.push_back(at);
                bridges.push_back(to);
            }
        }

        else {
            low[at] = min(low[at], ids[to]);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v = 9;
    int id = -1;
    vector< vector<int> > edges(v);
    edges[0].push_back(1);
    edges[0].push_back(2);
    edges[1].push_back(0);
    edges[1].push_back(2);
    edges[2].push_back(0);
    edges[2].push_back(1);
    edges[2].push_back(5);
    edges[2].push_back(3);
    edges[3].push_back(4);
    edges[3].push_back(2);
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


    vector<bool> visited(v, false);
    vector<int> bridges;

    for(int i = 0; i < v; i++) {
        if(!visited[v]) {
            bridgeSolve(i, edges, visited, -1, id, bridges);
        }
    }

    for(int i = 0; i < bridges.size(); i++) {
        cout << bridges[i] << " ";
    }
    cout << "\n";

    return 0;
}