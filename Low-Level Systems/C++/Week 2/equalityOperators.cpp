//
// Created by Florian Mealing on 30/05/2024.
//
#include <iostream>

using namespace std;

int main(){
    bool equalResult {false};
    bool notEqualResult {false};

    int num1{}, num2{};

    cout << boolalpha; // will display true/false instead of 1/0 for booleans

    cout << "Enter two integers separated ny a space: ";
    cin >> num1 >> num2;
    equalResult = (num1 == num2);
    notEqualResult = (num1 != num2);
    cout << "Comparison result (equals): " << equalResult << endl;
    cout << "Comparison result (not equals): " << notEqualResult << endl;

    return 0;
}
