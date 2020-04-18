 #include<iostream>
 #include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        int x = grid.size(), y = 0, numIslands = 0;
        if(x) y = grid[0].size();
            
        // iterate through grid and call findIsland when grid[i][j] = '1'
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                if(grid[i][j] == '1'){
                    findIsland(i, j, grid);
                    numIslands++;
                }
            }
        }
        return numIslands;
    }
private:
    void findIsland(int a, int b, vector<vector<char> > &grid) {
        int x = grid.size(); int y = grid[0].size();
            
        // if out of bounds or not '1', return
        if( a < 0 or b < 0 or a >= x or b >= y or grid[a][b] != '1') return;
            
        // set the '1' to be '0' so not recounted
        grid[a][b] = '0';
            
        // recurse in all 4 directions
        int changeX[4] = {0,-1,1,0}, changeY[4] = {-1,0,0,1};
        for(int i = 0; i < 4; i++)  findIsland(a + changeX[i], b + changeY[i], grid);
        
    }
    
    
    
    
/*
int isSafe(vector<vector<char>> &grid, int row, int col, vector<vector<bool>> &visited)
    {
        // row number is in range, column
        // number is in range and value is 1
        // and not yet visited
        int r = grid.size();
        int c = grid[0].size();
        return (row >= 0) && (row < r) && (col >= 0) && (col < c) && (grid[row][col] == '1' &&          !visited[row][col]);
    }


void DFS(vector<vector<char>>&grid, int row, int col, vector<vector<bool>> &visited) {
    vector<int> rowNbr = { -1,  0, 0, 1 };
    vector<int> colNbr = {  0, -1, 1, 0 };
        
    visited[row][col] = true;
        
    for(int k = 0; k < 4; k++) {
        if (isSafe(grid, row + rowNbr[k], col + colNbr[k], visited))
            DFS(grid, row + rowNbr[k], col + colNbr[k], visited);
    }
}
     
int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, 0));
    int count = 0;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            // If a cell with value 1 is not
            if (grid[i][j] =='1' && !visited[i][j]) {
                // visited yet, then new island found
                // Visit all cells in this island.
                DFS(grid,i ,j, visited);
  
                // and increment island count
                ++count;
            }
    
  
    return count;
}
 */
};

int main() {
    vector<vector<char> > grid = {{'1', '1', '0', '0','0'}, {'1', '1', '0', '0','0'}, {'0', '0', '1', '0','0'}, {'0', '0', '0', '1','1'}};
    
    Solution s;

    cout <<"Number of Islands are: " << s.numIslands(grid);
    
    return 0;
}
