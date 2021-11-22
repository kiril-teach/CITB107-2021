#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int x;
    int smallest = INT_MAX;
    while(cin >> x) {
        if (x < smallest) {
            smallest = x;
        }
    }
    if (!cin.eof()) {
        cerr << "Could not read the entire input!" << endl;
        return 1;
    }
    cout << smallest << endl;
    return 0;
}