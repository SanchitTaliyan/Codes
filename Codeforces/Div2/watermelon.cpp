#include <iostream>

using namespace std;


int main() {
    int w;

    cin>>w;

    if(w%2 == 0 && w > 2) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }

    return 0;
}