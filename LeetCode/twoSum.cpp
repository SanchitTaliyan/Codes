#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int n = nums.size();
        int left = 0, right = n-1, sum;
        vector<int> ans;
        int n1 = -1, n2 = -1;

        while(left < right) {
            sum = temp[left] + temp[right];
            if(sum == target) {
                int i = 0;
                while(n1 == -1 || n2 == -1) {
                    if(i<n && nums[i] == temp[left] && n1 == -1){n1 = i; i++;}
                    if(i<n && nums[i] == temp[right] && n2 == -1) n2 = i;
                    i++;
                }
                ans.push_back(n1);
                ans.push_back(n2);
                return ans;
            }
            else if(sum < target) left++;
            else right--;
        }
        return ans;
    }
};
