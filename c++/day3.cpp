#include<iostream>
#include<climits>

using namespace std; //std is a namespace

int main() {
    float annualSalary;
    cout << "Please enter your annual salary: ";
    cin >> annualSalary;
    float monthlySalary = annualSalary / 12;

    cout << "Your monthly salary is: " << monthlySalary << endl;

    cout << "In 10 years you will earn: " << annualSalary * 10 << endl;

    char character = 'a';

    cout << "size of int: " << sizeof(int) << " bytes\n";

    cout << "Int min value is: " << INT_MIN << endl;
    cout << "Int max value is: " << INT_MAX << endl;

    cout << "Size of unsigned int is: " << sizeof(unsigned int) << " bytes" << endl;
    cout << "Max value of unsigned int is: " << UINT_MAX << endl;

}

/*
    1. data type overflow
    2. can only use '_' special character for naming variables.
    3. variable names can't begin with number and no space between variable name.
    4. double is 2*sizeOf float.
    5. 1 byte = 8 bit
    6. In 4 byte of int there are 32 bits, 1st bit is for +/- detemination.
    7. Learn binary expansion formula.
*/