#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        if(grid.empty() || grid[0].empty())
            return 0;
        
        int H = grid.size();
        int W = grid[0].size();
        
        vector<vector<int>> cost(H, vector<int>(W, INT_MAX));
        cost[0][0] = grid[0][0];
        
         for(int row = 0; row < H; row++) {
            for(int col = 0; col < W; col++) {
                if(row == 0 && col > 0)
                    cost[row][col] = cost[row][col-1] + grid[row][col];
                else if(col == 0 && row > 0) {
                    cost[row][col] = cost[row - 1][col] + grid[row][col];
                }
            }
         }
        
        for(int row = 1; row < H; row++) {
            for(int col = 1; col < W; col++) {
                cost[row][col] = min(cost[row - 1][col] , cost[row][col - 1]) + grid[row][col];
            } 
        }
        
        return cost[H-1][W-1];
    }
};