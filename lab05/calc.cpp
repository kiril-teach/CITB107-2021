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
    // cycle:
    cin >> x >> op >> y;
    if (op == '+') {
        r = x + y;
    }
    else if (op == '/') {
        r = x / y;
    }
    cout << r << endl;
    // end of cycle

    return 0;
}