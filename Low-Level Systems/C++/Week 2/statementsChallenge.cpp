#include <iostream>

using namespace std;

/*
 * Section 8 Challenge
 * For this probram I will be using US dollars and cents
 *
 * Write a program that asks the user to enter the following:
 * An integer representing the number of cents
 *
 * You may assume that the number of cents entered os greater than or equal to zero
 *
 * The program should then display how to provide that change to the user/
 * In the US:
 *  1 dollar is 100 cents
 *  1 quarter is 25 cents
 *  1 dime is 10 cents
 *  1 nickel is 5 cents
 *  1 penny is 1 cent
 *
 *  Here is a simple run:
 *
 *  Enter the amount of cents: 92
 *  You can provide this change as follows:
 *      dollars: 0
 *      quarters: 3
 *      dimes: 1
 *      nickels: 1
 *      pennies: 2
 */

int main(){
    int numCents {};
    int numDollar {};
    int numQuarter {};
    int numDime {};
    int numNickel {};
    int numPennies {};

    const int nickelInCents = 5;
    const int dimeInCents = 10;
    const int quarterInCents = 25;
    const int dollarInCents = 100;

    cout << "Enter the amount of cents: ";
    cin >> numCents;

    // Calculate the number of each coin
    numDollar = numCents / dollarInCents;
    numCents %= dollarInCents; // update number of cents

    numQuarter = numCents / quarterInCents;
    numCents %= quarterInCents; // update the number of cents

    numDime = numCents / dimeInCents;
    numCents %= dimeInCents;

    numNickel = numCents / nickelInCents;
    numCents %= nickelInCents;

    numPennies = numCents;

    // Display the result
    cout << "Dollars: " << numDollar << endl;
    cout << "Quarters: " << numQuarter << endl;
    cout << "Dimes: " << numDime << endl;
    cout << "Nickels: " << numNickel << endl;
    cout << "Pennies: " << numPennies << endl;

    return 0;
}
