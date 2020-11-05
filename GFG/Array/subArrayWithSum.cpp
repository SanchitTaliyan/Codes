#include <iostream>
#include <vector>

using namespace std;

vector<int> sum(vector<int> v, int n, int s) {
    vector<vector<int> > dp (n, vector<int> (n, 0));
    vector<int> ans;

    dp[0][0] = v[0];

    for(int j = 1 ; j < n; j++) {
        dp[0][j] = dp[0][j-1] + v[j];
        if(dp[0][j] == s){
            ans.push_back(0);
            ans.push_back(j);

            return ans;
        }
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = i ; j < n; j++) {
            dp[i][j] = dp[i-1][j] - dp[0][i-1];
            if(dp[i][j] == s) {
                ans.push_back(i);
                ans.push_back(j);

                return ans;
            }
        }
    }
    ans.push_back(-1);
    return ans;
}


int main() {
    int T;
    cout << "Enter number of Test Cases"<< endl;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int N, S;
        cout << "Enter size of array and the required sum"<<endl;
        cin >> N >> S;

        vector<int> V(N);
        cout << "Enter array"<<endl;
        for(int j = 0; j < N; j++) {
            cin >> V[j];
        }

        vector<int> ans = sum(V, N, S);

        if(ans.size() == 2)
            cout << ans[0] + 1<< " " << ans[1] + 1 << endl;
        else
            cout << ans[0] << endl;

    }

    return 0;
}