#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n, m, a;

    cin >> n >> m >> a;

    //cout << ceil(n/a) << "\n";
    //cout <<ceil(m/a)<< "\n";

    unsigned long long ans = ceil((double)m/a) * ceil((double)n/a);

    cout << ans;

    return 0;
}