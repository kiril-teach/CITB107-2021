#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

// eval an expression in the form of "x + y"
float eval(string expr) {
    float x, y;
    char op;
    stringstream ss(expr);
    ss >> x >> op >> y;
    if (ss.fail()) {
        cerr << "Could not parse expression." << endl;
        return 0;
    }

    switch (op) {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        if (y == 0) {
            cerr << "Cannot divide by zero!" << endl;
            return 0;
        }
        return x / y;
    default:
        cerr << "Unrecognized operator: " << op << endl;
        return 0;
    }
}

int main()
{
    assert(eval("1+2") == 3);
    assert(eval("1 + 2") == 3);
    assert(eval("4-3") == 1);
    assert(eval("9/2") == 4.5);
    assert(eval("3*4") == 12);
    assert(eval("5/0") == 0);

    string expr;
    while(getline(cin, expr)) {
        float result = eval(expr);
        cout << result << endl;
    }
    if (!cin.eof()) {
        cerr << "Cannot read input!" << endl;
        return 1;
    }

    return 0;
}