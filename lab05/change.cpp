#include <iostream>
#include <iomanip>

using namespace std;

/*
Input: 
-------------------
4380 10000

Output
-------------------
Change: 56.20
1x 50.00 // 5620 / 5000 = 1 rem 620
1x 5.00 // 620 / 500 = 1 rem 120
1x 1.00
1x 0.20
*/

int main()
{
    int price, paid;
    cin >> price >> paid;
    if (cin.fail()) {
        cerr << "Could not read input!" << endl;
        return 1;
    }
    if (paid < 0 || price < 0) {
        cerr << "Negative price or paid amount!" << endl;
        return 1;
    }
    if (paid < price) {
        cerr << "Paid less than the price!" << endl;
        return 1;
    }

    cout << fixed << setprecision(2);

    int change = paid - price;
    cout << "Change: " << change/100.0 << endl;

    int left = change;

    int count2bgn = left / 200;
    left = left % 200;
    if (count2bgn > 0) cout << count2bgn << "x " << 2.00 << endl;
    
    int count1bgn = left / 100;
    left = left % 100;
    if (count1bgn > 0) cout << count1bgn << "x " << 1.00 << endl;

    int count50st = left / 50;
    left = left % 50;
    if (count50st > 0) cout << count50st << "x " << 0.50 << endl;

    int count20st = left / 20;
    left = left % 20;
    if (count20st > 0) cout << count20st << "x " << 0.20 << endl;

    int count10st = left / 10;
    left = left % 10;
    if (count10st > 0) cout << count10st << "x " << 0.10 << endl;

    int count1st = left;
    if (count1st > 0) cout << count1st << "x " << 0.01 << endl;
    

    return 0;
}