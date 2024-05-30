//
// Created by Florian Mealing on 30/05/2024.
//
#include <iostream>

using namespace std;

int main() {
    int num {};
    const int lower {10};
    const int upper {20};
    bool withinBounds {false};
    bool outsideBounds {false};

    cout << boolalpha;

    // Determine if an entered integer is between two other integers
    // assume lower < upper
    cout << "Enter an integer - the bounds are " << lower << " and " << upper << ": ";
    cin >> num;

    withinBounds = (num > lower && num < upper);
    cout << num << " is between " << lower << " and " << upper << ": " << withinBounds << endl;

    // Determine if an entered integer is outside two other integers
    // assume lower < upper
    cout << "\nEnter an integer - the bounds are " << lower << " and " << upper << ": ";
    cin >> num;

    outsideBounds = (num < lower || num > upper);
    cout << num << " is outside " << lower << " and " << upper << ": " << outsideBounds << endl;

    return 0;
}
