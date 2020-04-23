#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        
        unordered_map<int, int> map;
        
        int count = 0;
        int sum = 0;
        
        for(int i = 0; i < len; i++) {
            sum += nums[i];
            
            if(sum == k) count++;
            
            if(map.find(sum - k) != map.end())
                count += map[sum-k];
            
            map[sum]++;
        }
        
        return count;
    }
};