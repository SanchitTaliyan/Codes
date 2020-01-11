#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int romanToInt(string s) {
    int i = 0;
    int count = 0;
    int N = s.size();
    while(i < N) {
        // if we encounter a '|'
        if(s[i] == 'I') {
            if((i + 1) < N && s[i+1] == 'V') {
                count += 4;
                i++;
            }
            else if((i + 1) < N && s[i+1] == 'X') {
                count += 9;
                i++;
            }
            else {
                count += 1;
            }
            //i++;               //add it in the end
        }

        // If we encounter a 'X'
        if(s[i] == 'X') {
            if((i + 1) < N && s[i+1] == 'L') {
                count += 40;
                i++;
            }else if((i + 1) < N && s[i+1] == 'C'){
                count += 90;
                i++;
            }else {
                count += 10;
            }
            //i++;              // add it in the end
        }

        // If we encounter a 'L'
        if(s[i] == 'L') {
            count += 50;
            //i++;             // add it in the end
        }

        // If we encounter a 'C'
        if(s[i] == 'C') {
            if((i + 1) < N && s[i+1] == 'D') {
                count += 400;
                i++;
            }else if((i + 1) < N && s[i+1] == 'M') {
                count += 900;
                i++;
            }
            else {
                count += 100;
            }
            //i++;             // add it in the end
        }

        // If we encounter a 'D'
        if(s[i] == 'D') {
            count += 500;
            //i++;             // add it in the end
        }

        // If we encounter a 'M'
        if(s[i] == 'M') {
            count += 1000;
        }

        cout << i << s[i];
        i++;
    }

    return count;
}

int main()
 {
	//code
	int T;
	cin >> T;
	while(T--) {
	    string s;
	    cin >> s;

	    cout << romanToInt(s) << endl;
	}
	return 0;
}
