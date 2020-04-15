#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    
    /// If want to do without using substr function
    /*
    string doShift (string s, int n) {
        string s1 = "", s2 = "";
        int len = s.length();
        for(int i = len - n; i < len; i++) {
            s1 += s[i];
        }
        for(int i = 0; i < len - n; i++) {
            s2 += s[i];
        }
        
        return s1 + s2;
    }
     */
    
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int finalShift = 0;
        int len = shift.size(); 
        for(int i = 0; i < len; i++){
            if(shift[i][0] == 0) {
                finalShift += -1 * shift[i][1];
            }
            else finalShift += shift[i][1];
        }
        
        finalShift = finalShift % len;
        
        int n = s.length();
        if(finalShift < 0) finalShift += n;
        
        //return doShift(s, finalShift);
        
        return s.substring(n - finalShift) + s.substring(0, n - finalShift);
    }
};
