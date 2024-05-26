#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

// This program will calculate the area of a room in square feet

int mainVariables() {
    // VariableType VariableName;
    // int, double, string, char, objects
    // begins with letter or underscore but not number or already defined variables

    int roomWidth {0};
    int roomLength{0};

    cout << "Enter the width of the room: ";
    cin >> roomWidth;

    cout << "Enter the length of the room: ";
    cin >> roomLength;

    cout << "The area of the room is " << roomWidth * roomLength << " square feet" << endl;

    return 0;
}

// Global and local variables
int age {18}; // Global variable
int mainGlobalVariables(){
    int age {16}; // Local variable
    cout << age << endl;

    return 0;
}

// Primitive types
int mainPrimitives(){
    // Character type
    char middleInitial {'J'};
    cout << "My middle initial is " << middleInitial << endl;

    // Integer Types
    unsigned short int examScore {55};
    cout << "My exam score was " << examScore << endl;

    int countriesRepresented {65};
    cout << "There were " << countriesRepresented << " countries represented in my meeting" << endl;

    long long peopleOnEarth {7'600'000};
    cout << "There are about " << peopleOnEarth << " people on earth" << endl;

    // Floating Point Types
    float car_payment {401.23};
    cout << "My car payment is " << car_payment << endl;

    double pi {3.14159};
    cout << "Pi is " << pi << endl;

    long double largeAmount {2.7e120};
    cout << largeAmount << " is a very big number" << endl;

    // Boolean Number
    bool gameOver {false};
    cout << "The value of gameOver is " << gameOver << endl;

    // Overflow Example
    short value1 {30000};
    short value2 {1000};
//    short product {value1 * value2};

//    cout << "The product of " << value1 << " and " << value2 << " is " << product << endl;

    return 0;
}

int mainSizeOf(){
    cout << "sizeof information" << endl;
    cout << "==================" << endl;

    cout << "char: " << sizeof(char) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << endl;
    cout << "short: " << sizeof(short) << endl;
    cout << "long: " << sizeof(long) << endl;
    cout << "long long: " << sizeof(long long) << endl;

    return 0;
}

/*
     * Frank's Carpet Cleaning Service
     * Charges £30 per room
     * Sales tax rate is 6%
     * Estimates are valid for 30 days
     *
     * Prompt the user for the number of rooms they would like cleaned
     * and provide an estimate such as:
     *
     * Estimate for carpet cleaning service
     * Number of rooms
     * Price per room
     * Cost
     * Tax
     * ===================================================================
     * Total estimate:
     * This estimate is valid for 30 days
     */
int main(){
    int numSmallRooms {0};
    int numLargeRooms {0};
    const double pricePerSmallRoom {25};
    const double pricePerLargeRoom {35};
    const double taxRate {0.06};
    const int estimateExpiry = 30; // days

    cout << "Hello, welcome to Frank's cleaning service \n\n";

    cout << "Enter the number of small rooms: ";
    cin >> numSmallRooms;
    cout << "Enter the number of large rooms: ";
    cin >> numLargeRooms;

    double cost = numSmallRooms * pricePerSmallRoom + numLargeRooms * pricePerLargeRoom;
    double tax = cost * taxRate;
    double totalEstimate = cost + tax;

    cout << "\nEstimate for carpet cleaning service\n";
    cout << "-----------------------------------\n";
    cout << "Number of small rooms: " << numSmallRooms << endl;
    cout << "Number of large rooms: " << numLargeRooms << endl;
    cout << "Price per small room: £" << pricePerSmallRoom << endl;
    cout << "Price per large room: £" << pricePerLargeRoom << endl;
    cout << "Cost: £" << cost << endl;
    cout << "Tax: £" << tax << endl;
    cout << "===================================\n";
    cout << "Total estimate: £" << totalEstimate << endl;
    cout << "This estimate is valid for " << estimateExpiry << " days\n";

    return 0;
}







