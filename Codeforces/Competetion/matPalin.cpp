#include <iostream>
#include <vector>
#include<math.h>
#include <cmath>
#include <queue>

using namespace std;

long long countOperations(vector< vector<long long> > &mat, int r, int c) {
    int ur, dr;
    ur = 0;
    dr = r-1;

    long long numOp = 0;
    while(ur <= dr) {
        for(int i = 0; i < (c + 1)/2; i++) {
 
            if(ur != dr){
                long long avg;
                if(i == c - i - 1) {
                    avg = (mat[ur][i] + mat[dr][i]) / 2;
                    numOp += abs(mat[ur][i] - avg) + abs(mat[dr][i] - avg);
                    mat[ur][i] = avg;
                    mat[dr][i] = avg;
                }else {
                    avg = (mat[ur][i]  + mat[ur][c - i - 1] + mat[dr][i]  + mat[dr][c - i - 1]) / 4;

                    numOp += abs(mat[ur][i] - avg) + abs(mat[ur][c - i - 1] - avg) + abs(mat[dr][i] - avg) + abs(mat[dr][c - i - 1] - avg);
                    mat[ur][i] = avg;
                    mat[ur][c- i -1] = avg;
                    mat[dr][i] = avg;
                    mat[dr][c - i - 1] = avg;
                }
                
            }  
            else if(ur == dr) {
                if(i != c - 1 - i){
                    long long avg = (mat[ur][i] + mat[ur][c - i - 1]) / 2;
                    numOp += abs(mat[ur][i] - avg) + abs(mat[ur][c - i - 1] - avg);
                    mat[ur][i] = avg;
                    mat[ur][c- i -1] = avg;
                }
            }
            
        }

        ur++;
        dr--;
    }

    return numOp;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int r, c;
        cin >> r >> c;

        vector< vector<long long> > mat(r, vector<long long>(c));

        for(int j = 0; j < r; j++) {
            for(int k = 0; k < c; k++) {
                cin >> mat[j][k];
            }
        }

        long long ans = countOperations(mat, r, c);
        cout << ans << "\n";
    }
}