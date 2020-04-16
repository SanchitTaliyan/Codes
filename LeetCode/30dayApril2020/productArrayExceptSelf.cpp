#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp = 1;
        int len = nums.size();
        vector<int> product(len, 1);
        
        for(int i = 0; i < len; i++) {
            product[i] = temp;
            temp = temp * nums[i];
        }
        
        temp = 1;
        
        for(int i = len -1; i >= 0; i--) {
            product[i] *= temp;
            temp *= nums[i];
        }
        
        return product;
    }
};
