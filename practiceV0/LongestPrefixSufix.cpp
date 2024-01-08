#include <iostream>
#include <vector>
#include<string>
using namespace std;

int largest_prefix_suffix(const std::string &str) {
   
  int n = str.length();
   
  if(n < 2) {
    return 0;
  }
 
  int len = 0;
  int i = n/2;
   
  while(i < n) {
    if(str[i] == str[len]) {
      ++len;
      ++i;
    } else {
      if(len == 0) { // no prefix
        ++i;
      } else { // search for shorter prefixes
        --len;
      }
    }
  }
   
  return len;
 
}
 
// Driver code
int main() {
     
string s = "wrwbwrqwhwrwbw";
 
cout << largest_prefix_suffix(s);
 
return 0;
}
