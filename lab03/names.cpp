#include <iostream>

using namespace std;

/*
Read first and last name + year of birth.
Output: Initials + Age
*/

const int currentYear = 2021;

int main() {
    // Read input
    string firstName, lastName;
    int yearOfBirth;
    cin >> firstName >> lastName >> yearOfBirth;
    
    // Calculate
    string initials;
    initials.append(firstName.substr(0, 1));
    initials.append(lastName.substr(0, 1));
    
    int age = currentYear - yearOfBirth;

    // Print output
    cout << initials << " " << age << endl;

    return 0;
}