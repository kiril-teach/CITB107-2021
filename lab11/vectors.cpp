#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers; // []  e.g. [1,2,3,4,5,6,7]
    vector<string> names; // [] e.g. ["john", "jane", ...]
    vector< vector<int> > vv; // [] e.g. [ [1,2,3], [10,20,30,40,50] ]

    numbers.push_back(1); // [1]
    numbers.push_back(2); // [1,2]
    numbers.push_back(3); // [1,2,3]

    numbers.insert(numbers.begin(), 9); // [9,1,2,3]
    numbers.pop_back(); // [9,1,2]

    numbers.erase(numbers.begin()); // [1,2]

    cout << numbers[1] << endl; // prints 2, b/c index starts at 0
    cout << numbers[0] << endl; // prints 1, b/c index starts at 0

    // vv[1][2] will be 30, if the data in vv vector is [ [1,2,3], [10,20,30,40,50] ]

    cout << numbers.size() << endl; // prints 2

    for(int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    return 0;
}