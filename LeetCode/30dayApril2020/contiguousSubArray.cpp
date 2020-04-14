#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> sumLeft(nums.size());
        unordered_map<int, int> map;
        int maxSize = 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            (nums[i] == 0) ? sum += -1 : sum += 1;

            if(sum == 0) maxSize = i + 1;
            
            if(map.find(sum + n) != map.end()) {
                if(maxSize < i - map[sum + n])
                    maxSize = i - map[sum + n];
            }
            
            else {
                map[sum + n] = i;
            }
        }
        
        return maxSize;
    }
};