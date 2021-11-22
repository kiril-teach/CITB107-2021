#include <iostream>

using namespace std;

int main()
{
    int x, sum = 0;
    while(cin >> x) {
        sum += x;
    }
    if (!cin.eof()) {
        cerr << "Could not read the entire input!" << endl;
        return 1;
    }
    cout << sum << endl;
    return 0;
}