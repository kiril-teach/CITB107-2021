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

    float p = (a + b + c) / 2;
    float s = sqrt(p * (p-a) * (p-b) * (p-c));

    cout << s << endl;

    return 0;
}