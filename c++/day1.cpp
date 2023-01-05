#include<iostream> //includes file

using namespace std;   //include libraries

void printSomething();  //prototyping function

void printCrap(int x){
    cout << "Your favourite number is = " << x << endl;
    return;
}

//main function i.e. first function
int main() {
    cout << "Hello world!" << endl;
    cout << "How are you? \n";
    int a, b;
    int sum;

    cout << "Enter first number = ";
    cin >> a;
    //cout << endl;

    cout << "Enter second number = ";
    cin >> b;
    //cout << endl;

    sum = a + b;

    cout << "Sum of first number and second number is = " << sum << endl;

    if(sum > 21) {
        cout << "Entered sum is greater than 21 \n";
    }

    printSomething();
    printCrap(20);

    return 0;
}

//Functions
void printSomething(){
    cout << "This function can print something on the screen \n";
    return;
}

int calculateAge(){

}

// cout is stream output object
// << is stream insertion operator
// cin is input stream object