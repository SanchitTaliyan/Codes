#include <iostream>
#include <vector>

using namespace std;

long long findSide(long long a, long long b, long long c) {
    if(a == b && a == c) {
        return a;
    }
    if(b + c > a) {
        return (a + b + c)/2 - 1; 
    }else {
        long long l = a - b - c ;
        long long r = a + b + c;

        return (l + r) / 2;
    }
} 

int main() {
    int t;
    cin >>t;

    for(int i = 0; i < t; i++) {
        long long a, b, c;

        cin >> a;
        cin >> b;
        cin >> c;
        //cout << a << " " << b << " " << c << endl;
        long long d;
        if(a >= b && a >= c) {
            d = findSide(a, b, c);
        }else if(b >= a && b >= c) {
            d = findSide(b, a, c);
        }else {
            d = findSide(c, a, b);
        }

        cout << d << "\n";

    }

    return 0;
}