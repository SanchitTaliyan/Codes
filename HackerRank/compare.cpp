#include<math.h> 
#include<iostream>
#include<vector>

using namespace std;

vector<int> compare(int a , int b){
    vector<int> v;
    if(a>b){
        v.push_back(1);
        v.push_back(0);
    }
    if(a<b){
        v.push_back(0);
        v.push_back(1);
    }
    else{
        v.push_back(0);
        v.push_back(0);
    }

    return v;
}

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int n = a.size();
    vector<int> sum;
    int a1 = 0;
    int b1 = 0;

    for(int i = 0; i<n; i++){
        vector<int> k = compare(a[i], b[i]);
        a1 = a1 + k[0];
        b1 = b1 + k[1];
    }

    sum.push_back(a1);
    sum.push_back(b1);

    return sum;

}

int main(){

	vector<int> alice;
	alice.push_back(5);
	alice.push_back(6);
	alice.push_back(7);
	vector<int> bob;
	bob.push_back(3);
	bob.push_back(6);
	bob.push_back(10);

	vector<int> k = compareTriplets(alice, bob);

	cout<<k[0]<<" "<<k[1];

	cout<<"size of output is = "<<k.size();

	return 0;
}

