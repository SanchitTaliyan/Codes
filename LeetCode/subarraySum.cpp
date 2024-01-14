#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, vector<int>> map;
        vector<vector<int>> result;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(sum == k) {
                result.push_back({0, i});
                ans++;
            }
            
            if(map.find(sum - k) != map.end()) {
                for(auto starts: map[sum-k]) {
                    ans++;
                    result.push_back({starts+1, i});
                }
            }
            map[sum].push_back(i);
        }

        printRes(result);
        return ans;
    }

    void printRes(vector<vector<int>> result) {
        for(auto subarray: result) {
            cout << "Starts:" << subarray[0] << ", Ends:" << subarray[1] << endl;
        }
    }
};