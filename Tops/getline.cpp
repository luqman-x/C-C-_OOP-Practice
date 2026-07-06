#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

int main()
{
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age; // Leaves '\n' in the buffer

    // 1. CLEAR THE BUFFER
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string fullName;
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName); // Now works correctly!

    std::cout << "Age: " << age << ", Name: " << fullName << "\n";
    return 0;
}
