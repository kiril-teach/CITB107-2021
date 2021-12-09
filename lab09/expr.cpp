#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

bool parse(const string &expr, float &x, char &op, float &y) {
    stringstream ss(expr);
    ss >> x >> op >> y;
    if (ss.fail()) {
        return false;
    }
    return true;
}

// eval an expression in the form of "x + y"
float eval(float x, char op, float y, string &err) {
    err = "";
    switch (op) {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        if (y == 0) {
            err = "cannot divide by zero";
            return 0;
        }
        return x / y;
    default:
        err = "unrecognized operator";
        return 0;
    }
}

void test() {
    string err;
    assert(eval(1, '+', 2, err) == 3);
    assert(eval(4, '-', 3, err) == 1);
    assert(eval(9, '/', 2, err) == 4.5);
    assert(eval(3, '*', 4, err) == 12);

    assert(eval(5, '/', 0, err) == 0 && err == "cannot divide by zero");
    assert(eval(5, '%', 4, err) == 0 && err == "unrecognized operator");

    float x, y;
    char op;
    string expr = "1+2";
    assert(parse(expr, x, op, y) == true && x == 1 && op == '+' && y == 2);
    expr = "1 + 2";
    assert(parse(expr, x, op, y) == true && x == 1 && op == '+' && y == 2);
}

int main()
{
    test();
    string expr;
    while(getline(cin, expr)) {
        float x, y;
        char op;
        bool ok = parse(expr, x, op, y);
        if (!ok) {
            cerr << "Could not parse expression." << endl;
            continue;
        }
        string err;
        float result = eval(x, op, y, err);
        if (err != "") {
            cerr << "Error evaluating the expression: " << err << endl;
            continue;
        }
        cout << result << endl;
    }
    if (!cin.eof()) {
        cerr << "Cannot read input!" << endl;
        return 1;
    }

    return 0;
}