#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Challenge
int main(){
    /*
     * This challenge is about using a collection (list) of integers and allowing the user
     * to select options from a menu to perform operations on the list.
     *
     * Your program should display a menu options to the user as follows:
     *
     *  P - Print numbers
     *  A - Add a number
     *  M - Display the mean of the numbers
     *  S - Display the smallest number
     *  L - Display the largest number
     *  Q - Quit
     *
     *  Enter your choice:
     *
     * The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
     * If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
     * displayed again.
     *
     * If the user enters 'P' or 'p', you should display all the elements in the list.
     * If the list is empty you should display "[] - the list is empty"
     * If the list is not empty all the list element should be displayed inside square brackets separated by a space.
     * For example, [1 2 3 4 5]
     *
     * If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
     * which you will add to the list and then display it was added. For example, if the user enters 5
     * You should display, "5 added".
     * Duplicate entries OK
     *
     * If the user enters 'M' or 'm' you should calculate the mean or average of the elements in the list and display it.
     * If the list is empty you should display, "Unable to calculate the mean - no data"
     *
     * If the user enters 'S' or 's' you should display the smallest element in the list.
     * For example, if the list contains [2 3 4 5 1], you should display, "The smallest number is 1"
     * If the list is empty you should display, "Unable to determine the smallest number - list is empty"
     *
     * If the user enters 'L' or 'l' you should display the largest element in the list
     * For example, if the list contains [2 4 5 1], you should display "The largest number is 5"
     * If the list is empty you should display, "Unable to determine the largest number - list empty"
     *
     * If the user enters 'Q' or 'q' then you should display "Goodbye" and the program should terminate.
     */
    char choice{};
    vector<int> list{};

    do {
        // Display menu
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display the mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 'P' || choice == 'p') {
            if (list.empty()) {
                cout << "[] - the list is empty" << endl;
            } else {
                cout << "[ ";
                for (auto val : list) {
                    cout << val << " ";
                }
                cout << "]" << endl;
            }
        } else if (choice == 'A' || choice == 'a') {
            int num{};
            cout << "Enter an integer to add to the list: ";
            cin >> num;
            list.push_back(num);
            cout << num << " added." << endl;
        } else if (choice == 'M' || choice == 'm') {
            if (list.empty()) {
                cout << "Unable to calculate the mean - no data" << endl;
            } else {
                int sum{};
                double mean{};
                for (auto item : list) {
                    sum += item;
                }
                mean = static_cast<double>(sum) / list.size();
                cout << fixed << setprecision(2); // Set precision for mean output
                cout << "The mean is: " << mean << endl;
            }
        } else if (choice == 'S' || choice == 's') {
            if (list.empty()) {
                cout << "Unable to determine the smallest number - list is empty" << endl;
            } else {
                int min = list.at(0);
                for (auto item : list) {
                    if (item < min) {
                        min = item;
                    }
                }
                cout << "The smallest number is: " << min << endl;
            }
        } else if (choice == 'L' || choice == 'l') {
            if (list.empty()) {
                cout << "Unable to determine the largest number - list is empty" << endl;
            } else {
                int max = list.at(0);
                for (auto item : list) {
                    if (item > max) {
                        max = item;
                    }
                }
                cout << "The largest number is: " << max << endl;
            }
        } else if (choice == 'Q' || choice == 'q') {
            cout << "Goodbye" << endl;
            break;
        } else {
            cout << "Unknown selection, please try again" << endl;
        }
    } while (true);

    return 0;
}

// Nested Loops
int main8(){
//    for(int num1{1}; num1 <= 10; ++num1){
//        for(int num2{1}; num2 <= 10; ++num2){
//            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
//        }
//        cout << "--------------------" << endl;
//    }

    int numItems{};

    cout << "How many data items do you have? ";
    cin >> numItems;

    vector<int> data{};

    for(int i{1}; i <= numItems; i++){
        int dataItem{};
        cout << "Enter data item " << i << ": ";
        cin >> dataItem;
        data.push_back(dataItem);
    }

    cout << "\nDisplaying Histogram" << endl;
    for(auto val: data){
        for (int i{1}; i <= val; i++){
            if(i % 5 == 0)
                cout << "*";
            else
                cout << "-";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}

// do-while Loop
int main7(){
    char selection{};
    do {
        cout << "\n-------------------" << endl;
        cout << "1. Do this" << endl;
        cout << "2. Do that" << endl;
        cout << "3. Do something else" << endl;
        cout << "Q. Quit" << endl;
        cout << "\nEnter your selection: ";
        cin >> selection;

        if (selection == '1'){
            cout << "You chose 1 - doing this" << endl;
        } else if (selection == '2') {
            cout << "You chose 2 - doing that" << endl;
        } else if (selection == '3') {
            cout << "You chose 3 - doing something else" << endl;
        } else if (selection == 'Q' || selection == 'q'){
            cout << "Goodbye..." << endl;
        } else{
            cout << "Unknown option -- try again...";
        }


    } while (selection != 'q' && selection != 'Q');

    return 0;
}

// while Loop
int main6(){
//    int num{};
//    cout << "Enter a positive integer - start the countdown: ";
//    cin >> num;
//
//    while (num > 0) {
//        cout << num << endl;
//        num--;
//    }
//    cout << "Blastoff!" << endl;

//    int num{};
//    cout << "Enter a positive integer to count up to: ";
//    cin >> num;
//
//    int i{1};
//    while (num >= i) {
//        cout << i << endl;
//        i++;
//    }

//    int number{};
//
//    cout << "Enter an integer less than 100: ";
//    cin >> number;
//
//    while (number >= 100) { // !(number < 100)
//        cout << "Enter an integer less than 100: ";
//        cin >> number;
//    }
//    cout << "Thanks" << endl;

    bool done{false};
    int number{0};

    while (!done){
        cout << "Enter an integer between 1 and 5: ";
        cin >> number;
        if (number <= 1 || number >= 5)
            cout << "Out of range, try again" << endl;
        else{
            cout << "Thank you!" << endl;
            done = true;
        }
    }

    return 0;
}

// Range based for loop
int main5(){
    int scores[]{10, 20, 30};

    for(auto score: scores)
        cout << score << endl;

    vector<double> temperatures{87.9, 77.9, 80.0, 72.5};
    double averageTemp{};
    double total{};

    for (auto temp: temperatures)
        total += temp;

    if (!temperatures.empty())
        averageTemp = total / temperatures.size();

    cout << fixed << setprecision(1);
    cout << "Average temperature is " << averageTemp << endl;

    return 0;
}

// for loop
int main4(){
//    for (int i{1}; i <= 10; i++)
//        cout << i << endl;

//    for (int i{1}; i <= 10; i+=2)
//        cout << i << endl;

//    for (int i{10}; i >= 0; i--)
//        cout << i << endl;
//    cout << "Blastoff!";

//    for (int i{10}; i <= 100; i+=10)
//        if(i % 15 == 0)
//            cout << i << endl;

    for(int i{1}, j{5}; i <= 5; i++, j++){
        cout << i << " + " << j << " = " << (i + j) << endl;
    }

    cout << "=======================================" << endl;

    for (int i{1}; i <= 100 ; i++){
        cout << i;
        if (i % 10 == 0)
            cout << endl;
        else
            cout << " ";
    }

    cout << "=======================================" << endl;

    for (int i{1}; i <= 100 ; i++){
        cout << i << ((i % 10 == 0) ? "\n" : " ");
    }

    cout << "=======================================" << endl;

    vector <int> nums {10,20,30,40,50};
    for (unsigned i{0}; i < nums.size(); i++)
        cout << nums[i] << endl;

    cout << "=======================================" << endl;

    return 0;
}

// Conditional Operator
int main3(){
    int num{};

    cout << "Enter an integer: ";
    cin >> num;

    // if-else statement
    if (num % 2 == 0)
        cout << num << " is even" << endl;
    else
        cout << num << " is odd" << endl;

    // Conditional operator
    cout << num << " is " << ((num % 2 == 0) ? "even " : "odd ") << endl;

    int num1{}, num2{};

    cout << "Enter two integers separated by a space: ";
    cin >> num1 >> num2;

    if (num1 != num2){
        cout << "Largest: " << ((num1 > num2) ? num1 : num2) << endl;
        cout << "Smallest: " << ((num1 < num2) ? num1 : num2) << endl;
    } else {
        cout << "The numbers are the same" << endl;
    }

    return 0;
}

// Switch-case
int main2(){
    /*
     * Ask the user what grade they expect on an exam and
     * tell them what they need to score to get it.
     */
    char letterGrade{};

    cout << "Enter the letter grade you expect on the exam: ";
    cin >> letterGrade;

    switch (letterGrade) {
        case 'a':
        case 'A':
            cout << "You need a 90 or above, study hard!" << endl;
            break;
        case 'b':
        case 'B':
            cout << "You need 80-89 for a B, go study!"<< endl;
            break;
        case 'c':
        case 'C':
            cout << "You need 70-79, for an average grade" << endl;
            break;
        case 'd':
        case 'D':
            cout << "Hmmm, you should strive for a better grade. All you need is 60-69" << endl;
            break;
        case 'f':
        case 'F':
        {
            char confirm{};
            cout << "Are you sure (Y/N)? ";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y')
                cout << "Okay, I guess you didn't study...." << endl;
            else if (confirm == 'n' || confirm == 'N')
                cout << "Good - go study" << endl;
            else
                cout << "Illegal choice peasant" << endl; // was asked to add something smart
            break;
        }
        default:
            cout << "Sorry, that's not a valid grade";
    }

    return 0;
}

// Shipping project
//int main(){
//    /*
//     * Shipping cost calculator
//     *
//     * Ask the user for package dimension in inches
//     * length, width, height - these should be integers
//     *
//     * All dimensions must be 10 inches or less or we cannot ship it
//     *
//     * Base cost $2.50
//     * If package volume is greater than 100 cubic inches there is a 10% surcharge
//     * If package volume is greater than 500 cubic inches there is a 25% surcharge
//     */
//    int length{}, width{}, height{};
//    double baseCost{2.50};
//
//    const int tier1Threshold{100}; // volume
//    const int tier2Threshold{500}; // volume
//
//    int maxDimensionLength{10}; // inches
//
//    double tier1Surcharge{0.1}; // 10% extra
//    double tier2Surcharge{0.25}; // 25% extra
//
//    int packageVolume{};
//
//    cout << "Welcome to the package cost calculator" << endl;
//    cout << "Enter length, width and height of the package separated by spaces: ";
//    cin >> length >> width >> height;
//
//    if (length > maxDimensionLength || width > maxDimensionLength || height > maxDimensionLength) {
//        cout << "Sorry, package rejected - dimension exceeded" << endl;
//    } else {
//        double packageCost{};
//        packageVolume = length * width * height;
//        packageCost = baseCost;
//
//        if (packageVolume > tier2Threshold){
//            packageCost += packageCost * tier2Surcharge;
//            cout << "Adding tier 2 surcharge" << endl;
//        } else if (packageVolume > tier1Threshold){
//            packageCost += packageCost * tier1Surcharge;
//            cout << "Adding tier 1 surcharge" << endl;
//        }
//
//        cout << fixed << setprecision(2); // prints dollars nicely
//        cout << "The volume of your package is: " << packageVolume << endl;
//        cout << "Your package will cost $" << packageCost << " to ship" << endl;
//    }
//
//    return 0;
//}

// Nested if statement
//int main(){
//    int score{};
//    char letterGrade{};
//
//    cout << "Enter your score on the exam (0-100): ";
//    cin >> score;
//
//    if (score >= 0 && score <= 100){
//        if (score >= 90) {
//            letterGrade = 'A';
//        } else if (score >= 80) {
//            letterGrade = 'B';
//        } else if (score >= 70) {
//            letterGrade = 'C';
//        } else if (score >= 60) {
//            letterGrade = 'D';
//        } else {
//            letterGrade = 'F';
//        }
//        cout << "Your grade is: " << letterGrade << endl;
//        if (letterGrade == 'F')
//            cout << "Sorry, you must repeat the class" << endl;
//        else
//            cout << "Congratulations, you passed";
//
//    } else {
//        cout << "Sorry, " << score << " is not in range" << endl;
//    }
//
//    cout << endl;
//    return 0;
//}


// If else statement
//int main(){
//    int num{};
//    const int target{10};
//
//    cout << "Enter a number and I'll compare it to " << target << ": ";
//    cin >> num;
//
//    if (num >= target) {
//        cout << "\n=============================" << endl;
//        cout << num << " is greater than or equal to " << target << endl;
//        int diff{num - target};
//        cout << num << " is " << diff << " greater than " << target;
//    } else {
//        cout << "\n=============================" << endl;
//        cout << num << " is less than " << target << endl;
//        int diff{target - num};
//        cout << num << " is " << diff << " less than " << target;
//    }
//
//    return 0;
//}

// If statement
//int main(){
//    int num {};
//    const int min {10};
//    const int max {100};
//
//    cout << "Enter a number between " << min << " and " << max << ": ";
//    cin >> num;
//
//    if (num >= min){
//        cout << "\n======= If statement 1 =========" << endl;
//        cout << num << " is greater than or equal to " << min << endl;
//
//        int diff {num - min};
//        cout << num << " is " << diff << " greater than " << min << endl;
//    }
//
//    if (num <= max){
//        cout << "\n======= If statement 2 =========" << endl;
//        cout << num << " is less than or equal to " << max << endl;
//
//        int diff {max - num};
//        cout << num << " is " << diff << " less than " << max << endl;
//    }
//
//    if (num >= min && num <= max){
//        cout << "\n======= If statement 3 =========" << endl;
//        cout << num << " is in range " << endl;
//        cout << "This means statements 1 and 2 must also display" << endl;
//    }
//
//    if (num == min || num == max){
//        cout << "\n======= If statement 4 =========" << endl;
//        cout << num << " is right on the boundary" << endl;
//        cout << "This means all 4 statements display" << endl;
//    }
//
//    cout << endl;
//    return 0;
//}
