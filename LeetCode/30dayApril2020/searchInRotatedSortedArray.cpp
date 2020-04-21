#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        
        int low = 0, high = n - 1;
        int first = nums[0];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int midVal = nums[mid];
            if(midVal == target) return mid;
            bool midBig = midVal >= first;
            bool targetBig = target >= first;
            
            if(midBig == targetBig){
                if(target > midVal)
                    low = mid + 1;
                else high = mid - 1;
            }
            else
                if(midBig)
                    low = mid + 1;
                else high = mid - 1;
        }
        
        return -1;
    }
};