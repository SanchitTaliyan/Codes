#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int part(vector<int> &arr, int l, int r);

int kthSmallest(vector<int> &arr, int l, int r, int k) {

    if(k > 0 && k <= r - l + 1) {
        int position = part(arr, l, r);

        if(position - l == k - 1)
          return arr[position];

        else if(position - l > k - 1)
          return kthSmallest(arr, l, position - 1, k);

        return kthSmallest(arr, position + 1, r, k - position + l - 1);
    }
    return INT_MAX;
}

int part(vector<int> &arr, int l, int r) {
    int x = arr[r];
    int i = l;

    for(int j = l; j < r; j++) {
        if(arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap (arr[i], arr[r]);

    return i;
}



int main() {
	//code
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
	    int N;
	    cin >> N;
	    vector<int> arr(N);
	    for(int i = 0; i < N; i++) {
	        cin >> arr[i];
	    }
	    int k;
	    cin >> k;
	    int ans = kthSmallest(arr, 0, N-1, k);
	    cout << ans << endl;
	}
	return 0;
}
