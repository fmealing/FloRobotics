#include <iostream>
#include <vector>

using namespace std;

// Challenge
int main(){
    /*
     * Declare 2 empty vectors of integers named vector1 and vector2, respectively.
     *
     * Add 10 and 20 to vector1  dynamically using push_back
     * Display the elements in vector1 using the at() method as well as the size() method
     */
    vector<int> vector1 {};
    vector<int> vector2 {};

    vector1.push_back(10);
    vector1.push_back(20);

    for(int i=0; i<vector1.size(); i++){
        cout << "Element[" << i << "]: " << vector1.at(i) << endl;
    }

    cout << "Size of vector1: " << vector1.size() << endl;

    return 0;
}

// Vectors
//int main() {
////    vector <char> vowels; // empty
////    vector <char> vowels (5); // 5 initialised to zero
//    vector <char> vowels {'a', 'e', 'i', 'o', 'u'};
//
//    cout << vowels[0] << endl;
//    cout << vowels[4] << endl;
//
////    vector <int> test_scores(3); // 3 elements initialised to zero
////    vector <int> test_scores(3,100); // 3 elements all initialised to 100
//    vector <int> test_scores{100, 98, 89};
//
//    cout << "\nTest scores using array syntax: " << endl;
//    cout << test_scores[0] << endl;
//    cout << test_scores[1] << endl;
//    cout << test_scores[2] << endl;
//
//    cout << "\nTest scores using vector syntax: " << endl;
//    cout << test_scores.at(0) << endl;
//    cout << test_scores.at(1) << endl;
//    cout << test_scores.at(2) << endl;
//    cout << "\nThere are " << test_scores.size() << " scores in the vector" << endl;
//
//    cout << "\nEnter 3 test scores: ";
//    cin >> test_scores.at(0);
//    cin >> test_scores.at(1);
//    cin >> test_scores.at(2);
//
//    cout << "\nUpdated test scores: " << endl;
//    cout << test_scores.at(0);
//    cout << test_scores.at(1);
//    cout << test_scores.at(2);
//
//    cout << "\nEnter a test score to add to the vector";
//
//    int scoreToAdd{0};
//    cin >> scoreToAdd;
//
//    test_scores.push_back(scoreToAdd);
//    cout << "\nEnter one more test score to add to the vector: ";
//    cin >> scoreToAdd;
//    cout << "\nTest scores are now: " << endl;
//
//    cout << test_scores.at(0);
//    cout << test_scores.at(1);
//    cout << test_scores.at(2);
//    cout << test_scores.at(3);
//
//    cout << "\nThere are now " << test_scores.size() << " scores in the vector";
//
////    cout << "This should call an exception!!" << test_scores.at(10);
//
//    // Example of a 2D vector
//    vector <vector<int>> movieRatings {
//            {1, 2, 3, 4},
//            {1, 2, 3, 4},
//            {1, 2, 2, 4}
//    };
//
//    cout << "\nHere are the movie rating for reviewer #1 using Array syntax: " << endl;
//    cout << movieRatings[0][0] << endl;
//    cout << movieRatings[0][1] << endl;
//    cout << movieRatings[0][2] << endl;
//    cout << movieRatings[0][3] << endl;
//
//    cout << "\nHere are the movie rating for reviewer #1 using Vector syntax: " << endl;
//    cout << movieRatings.at(0).at(0) << endl;
//    cout << movieRatings.at(0).at(1) << endl;
//    cout << movieRatings.at(0).at(2) << endl;
//    cout << movieRatings.at(0).at(3) << endl;
//
//    return 0;
//}

// Arrays
//int main() {
//    char vowels[] {'a', 'e', 'i', 'o', 'u'};
//    cout << "\nThe first vowel is: " << vowels[0] << endl;
//    cout << "The last vowel is: " << vowels[4] << endl;
//
//    double hi_temps[] {90.1, 89.8, 77.53, 81.6};
//    cout << "\nThe first high temperature is: " << hi_temps[0] << endl;
//
//    hi_temps[0] = 100.7;
//    cout << "The first high temperature is now: " << hi_temps[0] << endl;
//
//    int test_scores[5] {}; // Always initialise arrays
//
//    cout << "\nThe First score at index 0: " << test_scores[0] << endl;
//    cout << "The Second score at index 1: " << test_scores[1] << endl;
//    cout << "The Third score at index 2: " << test_scores[2] << endl;
//    cout << "The Fourth score at index 3: " << test_scores[3] << endl;
//    cout << "The Fifth score at index 4: " << test_scores[4] << endl;
//
//    cout << "\nEnter 5 test scores: ";
//    cin >> test_scores[0];
//    cin >> test_scores[1];
//    cin >> test_scores[2];
//    cin >> test_scores[3];
//    cin >> test_scores[4];
//
//    cout << "The updated array is: " << endl;
//    cout << "\nThe First score at index 0: " << test_scores[0] << endl;
//    cout << "The Second score at index 1: " << test_scores[1] << endl;
//    cout << "The Third score at index 2: " << test_scores[2] << endl;
//    cout << "The Fourth score at index 3: " << test_scores[3] << endl;
//    cout << "The Fifth score at index 4: " << test_scores[4] << endl;
//
//    cout << "Notice what the value of the array nam,e is: " << test_scores << endl;
//    return 0;
//}

/*
* Course notes
 * Array:
 * - compound data type or data structure
 * - fixed size
 * - elements are all the same type
 * - Stored contiguously in memory
 * - Individual elements can be accessed by their position or index
 * - First element is at index 0
 * - Last element is at index size - 1
 * - No checking to see if you are out of bounds
 * - Always initialise arrays
 * - Very efficient
 * - Iteration is often used to process
 * - elementType arrayName [constant number of elements] {init list};
 *
 * Multi-Dimensional Array:
 * Element_Type array_name [dim1_size][dim2_size]
 *
 * Vectors:
 * - Container in the C++ STL
 * - An array that can grow and shrink in size at execution time
 * - Provides similar semantics and syntax as arrays
 * - Very efficient
 * - Can provide bounds checking
 * - Can use lots of cool functions like sort, reverse, find, and more
 * - Decalring: #include <vector>
 *              using namespace std;
 *
 *              vector <char> vowels;
 *              vector <int> test_scores;
 *
 *              vector <char> vowels (5); // Already set to 0
 *              vector <char> vowels {'a', 'e', 'i', 'o', 'u'};
*/
