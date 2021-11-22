#include <iostream>
#include <cmath> // this is needed to use sqrt

using namespace std;

/*
 Read 3 sides of a triangle
 Output its area
*/

int main() {
    float a, b, c;
    cin >> a >> b >> c;
    if (cin.fail()) {
        cerr << "Could not read input!" << endl;
        return 1;
    }
    
    if (a + b <= c or b + c <= a or a + c <= b) {
        cerr << "This is not a triangle!" << endl;
        return 1;
    }

    float p = (a + b + c) / 2;
    float s = sqrt(p * (p-a) * (p-b) * (p-c));

    cout << s << endl;

    return 0;
}