#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

class Expression {
public:
    Expression() {
        left = 1;
        right = 0;
        op = '+';
    }
    Expression(float x, char o, float y) {
        left = x;
        op = o;
        right = y;
    }
    float eval(string &err) {
        err = "";
        switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            if (right == 0) {
                err = "cannot divide by zero";
                return 0;
            }
            return left / right;
        default:
            err = "unrecognized operator";
            return 0;
        }
    }
    bool parse(string expr) {
        stringstream ss(expr);
        ss >> left >> op >> right;
        if (ss.fail()) {
            return false;
        }
        return true;
    }

private:
    float left;
    float right;
    char op;
};

void test() {
    string err;
    assert(Expression(1, '+', 2).eval(err) == 3);
    assert(Expression(4, '-', 3).eval(err) == 1);
    assert(Expression(9, '/', 2).eval(err) == 4.5);
    assert(Expression(3, '*', 4).eval(err) == 12);

    assert(Expression(5, '/', 0).eval(err) == 0 && err == "cannot divide by zero");
    assert(Expression(5, '%', 4).eval(err) == 0 && err == "unrecognized operator");

    Expression e;
    assert(e.parse("1+2") == true && e.eval(err) == 3);
    assert(e.parse("1 + 2") == true && e.eval(err) == 3);
}

int main()
{   
    string input;
    while(getline(cin, input)) {
        Expression expr;
        bool ok = expr.parse(input);
        if (!ok) {
            cerr << "Could not parse expression." << endl;
            continue;
        }
        string err;
        float result = expr.eval(err);
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