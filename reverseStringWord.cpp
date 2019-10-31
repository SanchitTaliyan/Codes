#include <bits/stdc++.h>
using namespace std;

void reverse(char *begin, char *end){
    char temp;
    while(begin<end){
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void reverseFun(char *target){
    char *wordStart = NULL;
    char *temp = target;
    while(*temp){
        if(wordStart == NULL && (*temp != '.'))
            wordStart = temp;
        if(wordStart && ((*(temp+1) == '.') || (*(temp + 1) == '\0'))){
            reverse(wordStart, temp);
            wordStart = NULL;
        }
        temp++;
    }
    reverse(target, temp-1);
}

int main() {
	//code
	int T;
	cin>>T;
	for(int i = 0; i<T; i++){
	    string s = "";
	    cin>>s;
	    char ch[s.length()+1];
	    for(int i = 0; i<s.length(); i++){
	        ch[i] = s[i];
	    }
	    //ch[i] = '\0';
	    reverseFun(ch);
	    if(i == T-1) cout<<ch;
	    else cout<<ch<<endl;
	}
	return 0;
}
