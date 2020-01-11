#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(string *begin, string *end){
    string temp;
    string *b = begin;
    string *e = end;
    while(b<e){
        temp = *b;
        *b++ = *e;
        *e-- = temp;
    }
}

void reverseFun(string *target){
    string *wordStart = NULL;
    string *temp = target;
    while(temp){
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
	    reverseFun(s);
	    if(i == T-1) cout<<s;
	    else cout<<s<<endl;
	}
	return 0;
}
