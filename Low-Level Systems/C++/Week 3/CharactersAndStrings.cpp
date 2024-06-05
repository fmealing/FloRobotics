#include <iostream>
#include <cstring> // for c-style function
#include <cctype> // for character-based functions
#include <string>

using namespace std;

// Challenge
int main(){
    /*
     * A simple and very old method of sending secret messages in the substitution is the substitution cipher.
     * You might have used this cipher with your friends when you were a kid.
     * Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
     * For example, every 'a' gets replaced with an 'X' and every 'b' gets replaced with a 'Z', etc.
     *
     * Write a program that asks the user to enter a secret message.
     *
     * Encrypt this message using th substitution cipher and display the encrypted message.
     * Then decryped the encrypted message back to the original mesdsage.
     *
     * You may use the 2 strings below for your substitution.
     * For example, to encrypt you can replace the character at position n in the alphabet
     * with the character at position n in key.
     *
     * To decrypt you can replace the character at position n in key
     * with the character at position n in the alphabet
     *
     */

    const string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const string key      {"XQWYVZHSIJRFBLKOPEUGCMADTNxqwyvzhsijrfblkopeugcmadtn"};

    string secret_message;
    cout << "Enter a secret message to decipher: ";
    getline(cin, secret_message);

    // Encrypt the message
    string encrypted_message;
    for (char c: secret_message){
        size_t position = alphabet.find(c);
        if (position != string::npos) {
            encrypted_message += key[position];
        } else {
            encrypted_message += c;
        }
    }

    // Decrypt the message
    string decrypted_message;
    for (char c: encrypted_message) {
        size_t position = key.find(c);
        if(position != string::npos) {
            decrypted_message += alphabet[position];
        } else {
            decrypted_message += c;
        }
    }

    // Display the encrypted and decrypted messages
    cout << "Encrypted message: " << encrypted_message << endl;
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}

// C++ strings
int main2(){
    string s0;
    string s1 {"Apple"};
    string s2 {"Banana"};
    string s3 {"Kiwi"};
    string s4 {"apple"};
    string s5 {s1};
    string s6 {s1, 0, 3};
    string s7 {10, 'X'};

    cout << s0 << endl;     // No garbage
    cout << s0.length() << endl;

    // Initialisation
    cout << "\nInitialisation" << "\n---------------------------------------------" << endl;
    cout << "s1 is initialised to: " << s1 << endl;
    cout << "s2 is initialised to: " << s2 << endl;
    cout << "s3 is initialised to: " << s3 << endl;
    cout << "s4 is initialised to: " << s4 << endl;
    cout << "s5 is initialised to: " << s5 << endl;
    cout << "s6 is initialised to: " << s6 << endl;
    cout << "s7 is initialised to: " << s7 << endl;

    // Comparison
    cout << "\nComparison" << "\n--------------------------------------------" << endl;
    cout << boolalpha;
    cout << s1 << " == " << s5 << ": " << (s1 == s5) << endl;
    cout << s1 << " == " << s2<< ": " << (s1 == s2) << endl;
    cout << s1 << " != " << s2 << ": " << (s1 != s2) << endl;
    cout << s1 << " < " << s2 << ": " << (s1 < s2) << endl;
    cout << s2 << " > " << s1 << ": " << (s2 > s1) << endl;

    // Assignment
    cout << "\nAssignment" << "\n--------------------------------------------" << endl;

    s1 = "Watermelon";
    cout << "s1 is now: " << s1 << endl;
    s2 = s1;
    cout << "s2 is now: " << s2;

    s3 = "Frank";
    cout << "s3 is now: " << s3 << endl;

    s3[0] = 'C';
    cout << "s3 change first letter to 'C': " << s3 << endl;
    s3.at(0) = 'P';
    cout << "s3 change first letter to 'P': " <<s3 << endl;

    // Concatenation
    s3 = "Watermelon";
    cout << "\nConcatenation" << "\n--------------------------------------------" << endl;

    s3 = s5 + " and " + s2 + "juice";
    cout << "s3 is now: " << s3 << endl;

    return 0;
}

// C-style Strings
int main1() {
    char first_name[20]{};
    char last_name[20]{};
    char full_name[50]{};
    char temp[50]{};

//    cout << first_name; // wil likely be garbage
    cout << "Please enter your first name: ";
    cin >> first_name;

    cout << "Please enter your last name: ";
    cin >> last_name;
    cout << "-------------------------------" << endl;

    cout << "Hello, " << first_name << " your name has " << strlen(first_name) << " characters" << endl;
    cout << "and your last name, " << last_name << " has " << strlen(last_name) << " characters" << endl;

    strcpy(full_name, first_name); // copy first_name to full name
    strcat(full_name, " "); // concatenate full name and space
    strcat(full_name, last_name); // concatenate last_name to full_name
    cout << "Your full name is " << full_name << endl;

//    cout << "---------------------------------" << endl;
//    cout << "Enter your full name: ";
//    cin >> full_name;
//    cout << "Your full name is " << full_name << endl;

    cout << "Enter your full name: ";
    cin.getline(full_name, 50);
    cout << "Your full name is " << full_name << endl;

    cout << "---------------------------------" << endl;
    strcpy(temp, full_name);
    if(strcmp(temp, full_name) == 0)
        cout << temp << " and " << full_name << " are the same" << endl;
    else
        cout << temp << " and " << full_name << " are different" << endl;
    cout << "---------------------------------" << endl;


    for(size_t i{0}; strlen(full_name); i++){
        if(isalpha(full_name[i]))
            full_name[i] = toupper(full_name[i]);
    }
    cout << "Your name is " << full_name << endl;

    cout << "---------------------------------" << endl;
    strcpy(temp, full_name);
    if(strcmp(temp, full_name) == 0)
        cout << temp << " and " << full_name << " are the same" << endl;
    else
        cout << temp << " and " << full_name << " are different" << endl;
    cout << "---------------------------------" << endl;

    cout << "Result of comparing" << temp << " and " << full_name << ": " << strcmp(temp,full_name) << endl;
    cout << "Result of comparing" << full_name << " and " << temp << ": " << strcmp(full_name, temp) << endl;

    return 0;
}
