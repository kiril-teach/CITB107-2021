#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> read() {
    vector<int> numbers;
    int x;
    while(cin >> x) {
        numbers.push_back(x);
    }
    return numbers;
}

// e.g. [1, 1, (2), 3, 4]
// e.g. [1, 1, 2, (3), 4, 5]
int median(vector<int> numbers) { // we don't want reference, we want a copy so that the original vector is unchanged
    sort(numbers.begin(), numbers.end());
    print(numbers);
    return numbers[numbers.size()/2];
}

int main()
{
    vector<int> numbers = read();
    if (!cin.eof()) {
        cerr << "Could not read the entire input!" << endl;
        return 1;
    }

    // e.g. [2, 1, 3, 1, 4]
    print(numbers);
    
    // will print out the sorted array + the median, e.g. [1, 1, (2), 3, 4]
    cout << median(numbers) << endl;

    // e.g. [2, 1, 3, 1, 4]
    print(numbers);

    return 0;
}