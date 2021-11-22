#include <iostream>

using namespace std;

int main()
{
    int x, y;
    
    cin >> x; // Read X
     if (cin.fail()) {
        cerr << "Cannot read X!" << endl;
        return 1; 
    }

    cin >> y;  // Read Y
    
    if (cin.fail()) {
        cerr << "Cannot read Y!" << endl;
        return 1; 
    }

    if (y == 0) {
        cerr << "Cannot divide by zero!" << endl;
        return 1;
    }

    int z = x / y; // Calculate X / Y
    cout << z << endl; // Print result

    return 0;
}