#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Input:
------
add 1
add 2
add 3
add 4
undo
sum
min
avg
*/

void print(const vector<int> v) {
    //E.g. [2, 1, 3]
    //  i = 0  1  2
    cerr << "[";
    for(int i = 0; i < v.size(); i++) {
        cerr << v[i];
        if (i < v.size()-1) {
            cerr << ",";
        }
    }
    cerr << "]" << endl;
}

void add(vector<int> &v, int n) {
    v.push_back(n);
}

void undo(vector<int> &v) {
    if (v.size() > 0) {
        v.pop_back();
    }
}

int sum(const vector<int> &v) {
    int s = 0;
    for (int i=0; i<v.size(); i++) {
        s += v[i];
    }
    return s;
}

int min(const vector<int> &v) {
    if (v.size() == 0) {
        return 0;
    }
    int best = v[0];
    for (int i=1; i<v.size(); i++) {
        best = min(best, v[i]);
    }
    return best;
}

float avg(const vector<int> &v) {
    if (v.size() == 0) {
        return 0;
    }
    return sum(v)/(float)v.size();
}

int main()
{
    vector<int> numbers;
    string cmd;
    while(cin >> cmd) {
        if (cmd == "add") {
            int n;
            cin >> n;
            add(numbers, n);
        } else if (cmd == "undo") {
            undo(numbers);
        } else if (cmd == "sum") {
            cout << sum(numbers) << endl;
        } else if (cmd == "min") {
            cout << min(numbers) << endl;
        } else if (cmd == "avg") {
            cout << avg(numbers) << endl;
        }
        print(numbers);
    }
    if (!cin.eof()) {
        cerr << "Could not read input!" << endl;
        return 1;
    }

    return 0;
}