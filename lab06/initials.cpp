#include <iostream>

using namespace std;

int main()
{
    string firstName, lastName;
    while (cin >> firstName >> lastName) {
        cout << firstName[0] << lastName[0] << endl;
    }
    return 0;
}