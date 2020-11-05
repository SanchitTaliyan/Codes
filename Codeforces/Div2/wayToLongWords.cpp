#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, i;

    cin >> n;

    for(i = 0; i < n; i++) {
        int len = 0;
        string s;
        cin >> s;

        len = s.size();
        if(len > 10) {
            string out = "";
            out += s[0];
            out += to_string(len - 2);
            out += s[len-1];
            cout << out << endl;
        }else {
            cout << s << endl;
        }
    }

    return 0;
}