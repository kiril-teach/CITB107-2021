#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

/*
F12345,4.00,5.50,6.00,3.50 => 19/4 = 4.75
F99999,6.00,5.50,5.00,5.00 => 21.50/4 = 5.375 => 5.375
---
10.125/2 = 5.0625
*/

double averagePerStudent(string line) {
    stringstream ss(line);
    string fn;
    getline(ss, fn, ',');
    cerr << fn << endl;
    double grade;
    double sum = 0;
    int count = 0;
    while(ss >> grade) {
        ss.get();
        cerr << "Grade: " << grade << endl;
        sum += grade;
        count++;
    }
    return sum/count;
}


int main() {
    // read grades per student

    assert(averagePerStudent("F12345,4.0,5.50,6.00,3.50") == 4.75);

    double sum = 0;
    int count = 0;
    string line;
    while (getline(cin, line)) {
        double avg = averagePerStudent(line);
        cerr << "Student average: " << avg << endl;
        sum += avg;
        count++;
    }

    double classAverage = sum / count;
    cout << classAverage << endl;
    return 0;
}