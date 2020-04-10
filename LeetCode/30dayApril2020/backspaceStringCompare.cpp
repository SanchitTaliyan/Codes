#include <stack>
#include<iostream>
#include<string.h>
using namespace std;

class Solution {

    void remove(string& s){
        int len = 0;
        
        for(int i = 0; i < (int)s.length(); i++) {
            if(s[i] == '#') {
                if(len > 0) {
                    len--;
                }
            }
            else {
                s[len] = s[i];
                len++;
            }
        }
        s.resize(len);
        
        //s[len] = NULL;
        
        /*
        for(char c: s){
            if(c == '#'){
                if(!s1.empty()) {
                    s1.pop_back();
                }
            }
            else{
                s1 += c;
            }
        }
        return s1;
        */
    }

public:
    bool backspaceCompare(string S, string T) {

        remove(S);
        remove(T);
        return S == T;

        /*
        stack<char> s1, s2;
        
        for(char c: S) {
            if(c != '#') s1.push(c);
            
            else if(!s1.empty()) s1.pop();
        }
        
        for(char c: T) {
            if(c != '#') s2.push(c);
            
            else if(!s2.empty()) s2.pop();
        }
        
        while(!s1.empty() && !s2.empty()) {
            if( s1.top() != s2.top() ) return false;
            s1.pop();
            s2.pop();
        }
        
        return s1.empty() && s2.empty();
        */
    }
};