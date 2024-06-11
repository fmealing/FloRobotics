#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

/*--------------------------------------------------------------------------------------------------------------------*/
// Section Challenge
/*
 * Your challenge for section 11 is to modularise your solution to the section 9 challenge by refactoring
 * your solution so that it uses functions.
 *
 * You decide how to modularise the program
 *
 * Here are a few hints:
 *  - Create functions for each major function
 *  - Keep the functions small
 *  - Remember the Boss/Worker analogy
 *  - Keep the vector declaration in the main function and pass the vector object to any function that requires it
 *
 *  DO NOT move the vector object outside the main and make it a global variable
 *
 *  - You can start defining a function that displays the menu
 *  - You can then define a function that reads the selection from the user and returns it in uppercase
 *  - Create functions for each menu option
 *  - Create functions that display the list of numbers, calculates the mean and so forth
 */
/*--------------------------------------------------------------------------------------------------------------------*/

// Function prototypes
void display_menu();
char get_choice();
void print_numbers(const vector<int> &list);
void add_number(vector<int> &list);
void display_mean(const vector<int> &list);
void display_smallest(const vector<int> &list);
void display_largest(const vector<int> &list);

int main() {
    char choice{};
    vector<int> list{};

    do {
        display_menu();
        choice = get_choice();

        switch (choice) {
            case 'P':
            case 'p':
                print_numbers(list);
                break;
            case 'A':
            case 'a':
                add_number(list);
                break;
            case 'M':
            case 'm':
                display_mean(list);
                break;
            case 'S':
            case 's':
                display_smallest(list);
                break;
            case 'L':
            case 'l':
                display_largest(list);
                break;
            case 'Q':
            case 'q':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unknown selection, please try again" << endl;
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}

void display_menu() {
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display the mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
}

char get_choice(){
    char choice;
    cin >> choice;
    return choice;
}

void print_numbers(const vector<int> &list){
    if (list.empty()) {
        cout << "[] - the list is empty" << endl;
    } else {
        cout << "[ ";
        for (auto val:list){
            cout << val << " ";
        }
        cout << "]" << endl;
    }
}

void add_number(vector<int> &list){
    int num{};
    cout << "Enter a number to add to the list: ";
    cin >> num;
    list.push_back(num);
    cout << num << " added." << endl;
}

void display_mean(const vector<int> &list){
    if (list.empty()){
        cout << "Unable to calculate mean - no data" << endl;
    } else {
        int sum{};
        double mean {};
        for (auto item:list){
            sum += item;
        }
        mean = static_cast<double>(sum) / list.size();
        cout << fixed << setprecision(2);
        cout << "The mean is: " << mean << endl;
    };
}

void display_smallest(const vector<int>& list) {
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
}
void display_largest(const vector<int>& list) {
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
}

/*--------------------------------------------------------------------------------------------------------------------*/
// Recursive Functions
unsigned long long factorial(unsigned long long n);
unsigned long long fibonacci(unsigned long long n);

unsigned long long factorial(unsigned long long n){
    if (n == 0)
        return 1;                   // base case
    return n * factorial(n-1);      // recursive case
}

unsigned long long fibonacci(unsigned long long n){
    if (n <= 1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main10(){
    cout << factorial(10) << endl;
    cout << fibonacci(10) << endl;
    return 0;
}

/*--------------------------------------------------------------------------------------------------------------------*/



/*--------------------------------------------------------------------------------------------------------------------*/
// Scope Rules
int main9(){
    int num = 100; // Local to main
    int num1 = 500; // Local to main

    cout << "Local num is " << num << " in main" << endl;

    {   // creates a new level of scope
        int num = 200; // local to this inner block in main
        cout << "Local num is: " << num << " in inner block in main" << endl;
        cout << "Inner block in main can see out - num1 is " << num1 << endl;
    }

    cout << "Local num is: " << num << " in main" << endl;
}

/*--------------------------------------------------------------------------------------------------------------------*/
// Pass by Reference
void pass_by_ref1(int &num);
void pass_by_ref2(string &s);
void pass_by_ref3(vector<string> &v);
void print_vector(const vector<string> &v); // const

void pass_by_ref1(int &num){
    num = 1000;
}

void pass_by_ref2(string &s){
    s = "Changed";
}

void pass_by_ref3(vector<string> &v){
    v.clear();
}

void print_vector(const vector<string> &v){
    for (auto s:v)
        cout << s << " ";
    cout << endl;
}

int main8(){
    int num {10};
    int another_num {20};

    cout << "num before pass_by_value1: " << num << endl;
    pass_by_ref1(num);
    cout << "num after pass_by_value1: " << num << endl;

    cout << "\nanother_num before calling pass_by_value1: " << another_num << endl;
    pass_by_ref1(another_num);
    cout << "another_num after calling pass_by_value1: " << another_num << endl;

    string s {"Florian"};
    cout << "\nString before calling pass_by_value2: " << s << endl;
    pass_by_ref2(s);
    cout << "String after calling pass_by_value2 " << s << endl;

    vector<string> stooges {"Larry", "Moe", "Curly"};
    cout << "\nStooges before calling poss_by_value3: ";
    print_vector(stooges);
    pass_by_ref3(stooges);
    cout << "Stooges before calling poss_by_value3: ";
    print_vector(stooges);
}
/*--------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------*/
// Overloading Functions
void print_array(const int arr[], size_t size);
void set_array(int arr[], size_t size, int value);

void print_array(const int arr[], size_t size) { // const
    for (size_t i{0}; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// set each array element to value
void set_array(int arr[], size_t size, int value){
    for (size_t i{0}; i < size; i++)
        arr[i] = value;
}

int main7(){
    int my_scores[] { 100, 98, 90, 86, 84 };

    print_array(my_scores, 5);
    set_array(my_scores, 5, 100);
    print_array(my_scores, 5);
}

/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
// Overloading Functions
void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector<string>);

void print(int num){
    cout << "Printing int: " << num << endl;
}

void print(double num){
    cout << "Printing double: " << num << endl;
}

void print(string s){
    cout << "Printing string: " << s << endl;
}

void print(string s, string t){
    cout << "Printing 2 strings : " << s << " and " << t << endl;
}

void print(vector <string> v){
    cout << "printing a vector of strings: ";
    for (auto s: v)
        cout << s + " ";
    cout << endl;
}

int main6(){
    print(100); // int
    print('A'); // character is always promoted to int

    print(123.5); // double
    print(123.3F);

    print("C-style string"); // C-style string is converted to a C++ string

    string s{"C++ string"};
    print(s); // C++ string

    print("C-style string", s); // First argument converted to a C++ string

    vector<string> three_stooges {"Larry", "Moe", "Curly"};
    print(three_stooges);

    return 0;
}


/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
// Default Arguments
double calc_cost(double base_cost, double tax_rate = 0.06, double shipping = 3.50);

void greeting(string name, string prefix = "Mr", string suffix = "");

double calc_cost(double base_cost, double tax_rate, double shipping){
    return base_cost += (base_cost * tax_rate) + shipping;
}

void greeting(string name, string prefix, string suffix){
    cout << "Hello " << prefix + " " << name + " " << suffix << endl;
}

int main5(){
    double cost {0};
    cost = calc_cost(100.0, 0.08, 4.25); // will use no defaults

    cout << fixed << setprecision(2);
    cout << "Cost is: " << cost << endl;

    cost = calc_cost(100.0, 0.08); // will use default shipping
    cout << "Cost is: " << cost << endl;

    cost = calc_cost(200.0); // will use default tax and shipping
    cout << "Cost is: " << cost << endl;

    cout << endl;

    greeting("Glenn Jones", "Dr.", "M.D.");
    greeting("James Rogers", "Professor", "Ph.D.");
    greeting("Frank Miller", "Dr.");
    greeting("Florian Mealing");

    cout << endl;
    return 0;
}

/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
// Function Parameters and Return Statement
void pass_by_value1(int num);
void pass_by_value2(string s);
void pass_by_value3(vector<string> v);
void print_vector(vector<string> v);

void pass_by_value1(int num){
    num = 100;
}

void pass_by_value2(string s){
    s = "Changed";
}

void pass_by_value3(vector<string> v){
    v.clear(); // delete all vector elements
}

//void print_vector(vector<string> v){
//    for (auto s: v)
//        cout << s << " ";
//    cout << endl;
//}

int main4(){
    int num {10};
    int another_num {20};

    cout << "num before pass_by_value1: " << num << endl;
    pass_by_value1(num);
    cout << "num after pass_by_value1: " << num << endl;

    cout << "\nanother_num before calling pass_by_value1: " << another_num << endl;
    pass_by_value1(another_num);
    cout << "another_num after calling pass_by_value1: " << another_num << endl;

    string s {"Florian"};
    cout << "\nString before calling pass_by_value2: " << s << endl;
    pass_by_value2(s);
    cout << "String after calling pass_by_value2 " << s << endl;

//    vector<string> stooges {"Larry", "Moe", "Curly"};
//    cout << "\nStooges before calling poss_by_value3: ";
//    print_vector(stooges);
//    pass_by_value3(stooges);
//    cout << "Stooges before calling poss_by_value3: ";
//    print_vector(stooges);

    return 0;
}

/*--------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------*/
// Function Prototypes - define at the beginning
double calc_volume_cylinder(double radius, double height);
double calc_area_circle(double radius);

void area_circle();
void volume_cylinder();

/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
// Function Definitions
const double pi {3.14159};

int main3(){
    area_circle();
    volume_cylinder();

    return 0;
}

double calc_area_circle(double radius){
    return pi * pow(radius, 2);
}

double calc_volume_cylinder(double radius, double height){
    return calc_area_circle(radius) * height;
}

void area_circle() {
    double radius {};
    cout << "\nEnter the radius of the circle: ";
    cin >> radius;

    cout << "The area of a circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

void volume_cylinder(){
    double radius {};
    double height {};

    cout << "\nEnter the radius of the cylinder: ";
    cin >> radius;

    cout << "\nEnter the height of the cylinder: ";
    cin >> height;

    cout << "The volume of a cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height) << endl;
}

/*--------------------------------------------------------------------------------------------------------------------*/

int main2(){
    int randomNumber {};
    size_t count{10}; // number of random numbers to generate
    int min {1};      // lower bound (inclusive)
    int max {6};      // upper bound (inclusive)

    // seed the random number generator
    // If you don't seed the generator you will get the same sequence of numbers every run

    cout << "RAND_MAX on my system is: " << RAND_MAX << endl;
    srand(time(nullptr));

    for(size_t i{1}; i<=count; i++){
        randomNumber = rand() % max + min; // generates a random number [min, max]
        cout << randomNumber << endl;
    }

    return 0;
}

int main1() {
    double num{};

    cout << "Enter a number(double): ";
    cin >> num;

    cout << "The sqrt of " << num << " is: " << sqrt(num) << endl;
    cout << "The cubed root of " << num << " is: " << cbrt(num) << endl;

    cout << "Th sine of " << num << " is: " << sin(num) << endl;
    cout << "The cosine of " << num << " is: " << cos(num) << endl;

    cout << "The ceil of " << num << " is: " << ceil(num) << endl;
    cout << "The flor of " << num << " is: " << floor(num) << endl;
    cout << "The round of " << num << " is: " << round(num) << endl;

    double power {};
    cout << "\nEnter a power to raise " << num << " to: ";
    cin >> power;
    cout << num << " raised to the " << power << "power is: " << pow(num, power) << endl;

    return 0;
}
