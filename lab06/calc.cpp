#include <iostream>
#include <iomanip>

using namespace std;

/*
Operations: +, -, *, /
Input:
4+2
9/3
Output:
6
3
*/

int main()
{
    int x, y, r;
    char op;
    while(cin >> x >> op >> y) {
        if (op == '+') {
            r = x + y;
        }
        else if (op == '-') {
            r = x - y;
        }
        else if (op == '*') {
            r = x * y;
        }
        else if (op == '/') {
            if (y == 0) {
                cerr << "Cannot divide by zero!" << endl;
                continue;
            }
            r = x / y;
        }
        else {
            cerr << "Unrecognized operator: " << op << endl;
            continue;
        }
        cout << r << endl;
    }
    if (!cin.eof()) {
        cerr << "Cannot read input!" << endl;
        return 1;
    }

    return 0;
}