#include <iostream>
#include <string>
#include <cctype>

// Namespace declaration
using namespace std;

// Function prototypes
string encrypt_message(const string &message, const string &alphabet, const string &key);
string decrypt_message(const string &message, const string &alphabet, const string &key);

int main() {
    /*
     * This program encrypts and decrypts a message using a substitution cipher.
     * Each letter of the alphabet is replaced by another letter in the key string.
     * The program asks the user to enter a secret message, encrypts it, and then decrypts it back to the original message.
     */

    // Define the alphabet and key for substitution
    const string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const string key      {"XQWYVZHSIJRFBLKOPEUGCMADTNxqwyvzhsijrfblkopeugcmadtn"};

    // Get the secret message from the user
    string secret_message;
    cout << "Enter a secret message to decipher: ";
    getline(cin, secret_message);

    // Encrypt the message
    string encrypted_message = encrypt_message(secret_message, alphabet, key);

    // Decrypt the message
    string decrypted_message = decrypt_message(encrypted_message, alphabet, key);

    // Display the encrypted and decrypted messages
    cout << "Encrypted message: " << encrypted_message << endl;
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}

// Function to encrypt a message
string encrypt_message(const string &message, const string &alphabet, const string &key) {
    string encrypted_message;
    for (char c : message) {
        size_t position = alphabet.find(c);
        if (position != string::npos) {
            encrypted_message += key[position];
        } else {
            encrypted_message += c;
        }
    }
    return encrypted_message;
}

// Function to decrypt a message
string decrypt_message(const string &message, const string &alphabet, const string &key) {
    string decrypted_message;
    for (char c : message) {
        size_t position = key.find(c);
        if (position != string::npos) {
            decrypted_message += alphabet[position];
        } else {
            decrypted_message += c;
        }
    }
    return decrypted_message;
}
