#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <limits.h>
 
using namespace std;

class Edge {
    public:
        int from, to, cost;

        /*
        Edge(int fr, int t, int c) {
            from = fr;
            to = t;
            cost = c;
        }
        */
};

int negativeCycle(vector<Edge> edges, int v, int e) {
    vector<int> dis(v, INT_MAX);
    dis[0] = 0;

    for(int i = 0; i <= v - 1; i++) {
        for(Edge edg: edges) {
            if(dis[edg.from] + edg.cost < dis[edg.to]) {
                dis[edg.to] = dis[edg.from] + edg.cost;
            } 
        }
    }

    for(int i = 0; i <= v - 1; i++) {
        for(Edge edg: edges) {
            if(dis[edg.from] + edg.cost < dis[edg.to])
                return 1;
        }
    }

    return 0;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int v, e;
        cin >> v >> e;

        vector<Edge> edges(e);

        for(int j = 0; j < e; j++) {
            int fr, t, co;
            cin >> fr >> t >> co;
            edges[j].from = fr;
            edges[j].to = t;
            edges[j].cost = co;
        }

        cout << negativeCycle(edges, v, e) << "\n";
    }
 
    return 0;
}