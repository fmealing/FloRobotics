/****************************************
 * Author: Florian Mealing
 ***************************************/

#include <iostream>
// using namespace std; // Use the entire std namespace
using std::cout; // Use only what you need
using std::cin;
using std::endl;


// This is a comment

/*
 * This is a multi-line comment
 * Which is pretty cool if you ask me
 * Don't comment the obvious
 * Keep a consistent comment style
 * Modify comment if you modify the code
 */

int main2() {
    int favorite_number;

    cout << "Enter your favorite number between 1 and 100: ";
    cin >> favorite_number;

    cout << "Amazing!! That's my favorite number too" << endl;
    cout << "No really!!, " << favorite_number << " is my favorite number number!" << endl;

    return 0;
}
