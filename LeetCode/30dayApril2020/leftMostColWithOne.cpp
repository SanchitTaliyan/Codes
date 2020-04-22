#include<iostream>
#include<vector>

using namespace std;

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        //O(m + n) solution
        vector<int> dim = binaryMatrix.dimensions();
        if(dim.size() < 2) return -1;
        int H = dim[0];
        int W = dim[1];
        
        
        int row = 0;
        int col = W-1;
        int leftCol = -1;
        while(row < H && col >= 0) {
            if(binaryMatrix.get(row, col) == 0) {
                row++;
            }
            else{
                leftCol = col;
                col--;
            }
        }
        
        return leftCol;
        
        
        
        
        
        // O(mlog(n)) solution
        /*
        int low = 0, high = W-1;
        int leftCol = INT_MAX;
        while(low <= high && low < W && high > 0) {
            int mid = low + (high - low) / 2;
            int i;
            for(i = 0; i < H; i++) {
                if(binaryMatrix.get(i, mid) == 1){
                    leftCol = min(leftCol, mid);
                    high = mid - 1;
                    break;
                }
            }
            if(i == H && binaryMatrix.get(i-1, mid) != 1) {
                low = mid + 1;
            }
        }
        
        if(leftCol != INT_MAX) return leftCol;
        
        return -1;
        */
    }
};