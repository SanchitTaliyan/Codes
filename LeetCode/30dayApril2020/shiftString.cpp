#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    
    string leftShift (string s, int n) {
        string s1 = "", s2 = "";
        
        for(int i = 0; i < n; i++) {
            s1 += s[i];
        }
        for(int i = n; i < s.length(); i++) {
            s2 += s[i];
        }
        
        return s2 + s1;
    }
    
    string rightShift (string s, int n) {
        string s1 = "", s2 = "";
        
        for(int i = s.length() - n; i < s.length(); i++) {
            s1 += s[i];
        }
        for(int i = 0; i < s.length() - n; i++) {
            s2 += s[i];
        }
        
        return s1 + s2;
    }
    
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
        
        if(finalShift == 0) return s;
        
        if(finalShift < 0) return leftShift(s, -1 * finalShift);
        
        else return rightShift(s, finalShift);
    }
};