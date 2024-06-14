#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**********************************************************************************************************************/
// Section Challenge
/*
 * Write a C++ function named apply_all that expects two arrays of integers and their sizes and dynamically allocates
 * a new array of integers whose size is the product of the two array sizes
 *
 * The function should loop through the second array and multiply each element across each element of array 1 and store
 * the product in the newly created array.
 *
 * The function should return a pointer to the newly allocated array.
 *
 * You can also write a print function that expects a pointer to an array of integers and ts size display the elements in
 * the array.
 */

#include <iostream>

using namespace std;

int *apply_all(const int arr1[], size_t size1, const int arr2[], size_t size2) {
    int *new_array = new int[size1 * size2];
    int position = 0;
    for (size_t i = 0; i < size2; ++i) {
        for (size_t j = 0; j < size1; ++j) {
            new_array[position] = arr2[i] * arr1[j];
            ++position;
        }
    }
    return new_array;
}

// Function to print the elements of an array
void print(const int arr[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int array1[] {1, 2, 3, 4, 5};
    int array2[] {10, 20, 30};

    cout << "Array 1: ";
    print(array1, 5);

    cout << "Array 2: ";
    print(array2, 3);

    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: ";
    print(results, 15);

    // Free the allocated memory
    delete[] results;

    return 0;
}


/**********************************************************************************************************************/
// What is a Reference?
int main10(){
    int num {100};
    int &ref {num};

    cout << num << endl;
    cout << ref << endl;


    num = 200;
    cout << "\n---------------------" << endl;
    cout << num << endl;
    cout << ref;

    ref = 300;
    cout << "\n---------------------" << endl;
    cout << num << endl;
    cout << ref << endl;

    cout << "\n------------------------------" << endl;
    vector<string> stooges {"Larry", "Moe", "Curly"};

    for (auto str: stooges)
        str = "Funny";
    for (auto str: stooges)
        cout << str << endl;

    cout << "\n-------------------------------" << endl;
    for (auto &str: stooges)
        str = "Funny";

    for (auto const &str: stooges)
        cout << str << endl;

    cout << endl;
    return 0;

}


/**********************************************************************************************************************/
// Return Pointer
int *create_array(size_t size, int init_value = 0){
    int *new_storage = new int[size];
    for (size_t i{0}; i < size; i++)
        *(new_storage + i) = init_value;
    return new_storage;
}

void display(const int *const array, size_t size){
    for (size_t i{0}; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main9(){
    int *my_array {nullptr};
    size_t size;
    int init_value{};

    cout << "\nHow many integers would you like to allocate? ";
    cin >> size;
    cout << "What value would you like them initialized to? ";
    cin >> init_value;

    my_array = create_array(size, init_value);
    cout << "\n---------------------" << endl;

    display(my_array, size);
    delete[] my_array;
    return 0;
}


/**********************************************************************************************************************/
// Passing Pointers 3
void display(const vector<string> *const v){
    for (auto str: *v)
        cout << str << " ";
    cout << endl;
}

void display(int *array, int sentinel){
    while (*array != sentinel)
        cout << *array++ << " ";
    cout << endl;
}

int main8(){
    cout << "-------------------" << endl;
    vector<string> stooges {"Larry", "Moe", "Curly"};
    display(&stooges);

    cout << "\n-------------------" << endl;
    int scores[] = {100, 98, 97, 79, 85, -1};
    display(scores, -1);

    cout << endl;
    return 0;
}

/**********************************************************************************************************************/
// Passing Pointers2
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main7(){
    int x{100}, y{200};
    cout << "\nx: " << x << endl;
    cout << "y: " << y << endl;

    swap(&x, &y);

    cout << "\nx: " << x << endl;
    cout << "y: " << y << endl;

    cout << endl;
    return 0;
}

/**********************************************************************************************************************/
// Passing Pointers1
void double_data(int *int_ptr){
    *int_ptr *= 2;
}

int main6(){
    int value {10};
    int *int_ptr {nullptr};

    cout << "Value: " << value << endl;
    double_data(&value);
    cout << "Value: " << value << endl;

    cout << "---------------------" << endl;
    int_ptr = &value;
    double_data(int_ptr);
    cout << "Value: " << value << endl;

    cout << endl;
    return 0;
}

/**********************************************************************************************************************/
// Pointer Arithmetic
int main5(){
    int scores[] {100, 95, 89, 68, -1};
    int *score_ptr {scores};

    while (*score_ptr != -1){
        cout << *score_ptr << endl;
        score_ptr++;
    }

    cout << "\n------------------------------------" << endl;
    score_ptr = scores;
    while (*score_ptr != -1){
        cout << *score_ptr++ << endl;
    }

    cout << "\n------------------------------------" << endl;
    string s1 {"Frank"};
    string s2 {"Frank"};
    string s3 {"James"};

    string *p1 {&s1};
    string *p2 {&s2};
    string *p3 {&s1};

    cout << boolalpha;
    cout << p1 << " == " << p2 << ": " << (p1 == p2) << endl;
    cout << p1 << " == " << p3 << ": " << (p1 == p3) << endl;

    cout << *p1 << " == " << *p2 << ": " << (*p1 == *p2) << endl;
    cout << *p1 << " == " << *p3 << ": " << (*p1 == *p3) << endl;

    p3 = &s3;
    cout << *p1 << " == " << *p3 << ": " << (*p1 == *p3) << endl;


    return 0;
}

/**********************************************************************************************************************/
// Relationship Between Arrays and Pointers
int main4(){
    int scores[] {100, 96, 89};

    cout << "Value of scores: " << scores << endl;

    int *score_ptr(scores);
    cout << "Value of score_ptr: " << score_ptr << endl;

    cout << "\nArray subscript notation ---------------" << endl;
    cout << scores[0] << endl;
    cout << scores[1] << endl;
    cout << scores[2] << endl;

    cout << "\nPointer subscript notation -------------" << endl;
    cout << score_ptr[0] << endl;
    cout << score_ptr[1] << endl;
    cout << score_ptr[2] << endl;

    cout << "\nPointer offset notation ----------------" << endl;
    cout << *score_ptr << endl;
    cout << *(score_ptr + 1)<< endl;
    cout << *(score_ptr + 2)<< endl;

    cout << "\nArray offset notation ------------------" << endl;
    cout << *scores << endl;
    cout << *(scores + 1)<< endl;
    cout << *(scores + 2)<< endl;

    return 0;
}

/**********************************************************************************************************************/
// Dynamic Memory
int main3(){
    int *int_ptr {nullptr};
    int_ptr = new int;
    cout << int_ptr << endl;
    delete int_ptr;

    size_t size{0};
    double *temp_ptr {nullptr};

    cout << "How many temps?";
    cin >> size;

    temp_ptr = new double[size];

    cout << temp_ptr << endl;

    delete [] temp_ptr;

    cout << endl;
    return 0;
};

/**********************************************************************************************************************/

int main2(){
    int score {100};
    int *score_ptr {&score};

    cout << *score_ptr << endl;

    *score_ptr = 200;

    cout << *score_ptr << endl;
    cout << score << endl;

    cout << "/n-------------------------------------------" << endl;
    double high_temp {100.7};
    double low_temp {37.4};
    double *temp_ptr {&high_temp};

    cout << *temp_ptr << endl;
    temp_ptr = &low_temp;
    cout << *temp_ptr << endl;

    cout << "/n-------------------------------------------" << endl;

    string name {"Florian"};
    string *string_ptr {&name};

    cout << *string_ptr << endl; // Florian
    name = "James";
    cout << *string_ptr << endl; // James

    cout << "/n-------------------------------------------" << endl;
    vector<string> stooges {"Larry", "Moe", "Curly"};;
    vector<string> *vector_ptr {nullptr};

    vector_ptr = & stooges;

    cout << "First stooge: " << (*vector_ptr).at(0) << endl; // Larry

    cout << "Stooges: ";
    for (auto stooge: *vector_ptr)
        cout << stooge << " ";
    cout << endl;

    cout << endl;
    return 0;
}

int main1() {
    int num {10};
    cout << "Value of num is: " << num << endl;
    cout << "sizeeof of num is: " << sizeof num << endl;
    cout << "Address of num is: " << &num << endl;

    int *p;
    cout << "\nValue of p is: " << p << endl; // garbage
    cout << "Adress of p is: " << &p << endl;
    cout << "sizeof of p is: " << sizeof p << endl;

    p = nullptr;
    cout << "\nValue of p is: " << p << endl;

    int *p1 {nullptr};
    double *p2 {nullptr};
    unsigned long long *p3 {nullptr};
    vector<string> *p4 {nullptr};
    string *p5 {nullptr};

    cout << "\nsizeof p1 is: " << sizeof p1 << endl;
    cout << "sizeof p2 is: " << sizeof p2 << endl;
    cout << "sizeof p3 is: " << sizeof p3 << endl;
    cout << "sizeof p4 is: " << sizeof p4 << endl;
    cout << "sizeof p5 is: " << sizeof p5 << endl;

    int score {10};
    double high_temp {100.7};

    int *score_ptr {nullptr};

    score_ptr = &score;
    cout << "Value of score is: " << score << endl;
    cout << "Address of score is: " << &score << endl;
    cout << "Value of score_ptr is: " << score_ptr << endl;

//    score_ptr = &high_temp;// Compiler Error

    return 0;
}
