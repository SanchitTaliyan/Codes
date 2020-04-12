#include <queue>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;
 

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq(less<int>(), stones);
        
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            if(a - b > 0) {
                pq.push(a-b);
            }
        }
        
        return pq.empty() ? 0 : pq.top();
        
        /*
        int length = stones.size();
        
        if(length == 1) return stones[0];
        if(length == 0) return 0;
        
        while(true) {
            sort(stones.begin(), stones.end(), greater<int>());
            if(stones[1] == 0) break;
            stones[0] = stones[0] - stones[1];
            stones[1] = 0;
        }
        
        return stones[0];
        */
    }
};