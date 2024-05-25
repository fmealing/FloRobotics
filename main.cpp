#include <iostream>

int main1() {
    int favourite_number;

    std::cout << "Enter your favourite number between 1 and 100: ";
    std::cin >> favourite_number;
    std::cout << "Amazing!! That's my favourite number too!" << std::endl;

    return 0;
}

int main2() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}

int main3() {
    int favourite_number = 69;

    std::cout << favourite_number << std::endl;
    return 0;
};

// Challenge
int main(){
    int favourite_number;

    std::cout << "Enter your favourite number between 1 and 100: ";
    std::cin >> favourite_number;
    std::cout << "Amazing!! That's my favourite number too!" << std::endl;
    std::cout << "No really!!, " << favourite_number << " is my favourite number too" << std::endl;
    return 0;
}