#include <iostream>
#include <iomanip>

using namespace std;

/*
Input: Glass 100 10

Output

                Item       Net       Tax
----------------------------------------
               Glass     90.91      9.09
*/

int main()
{
    // Read
    string desc;
    double price; // inclusive of tax
    int taxRatePercentage; // 10%

    cin >> desc >> price >> taxRatePercentage;

    // Calculation
    /*
    net + tax = gross
    tax = net * rate
    net * 1 + net * rate = gross
    net * (1 + rate) = gross
    net = gross / (1 + rate)
    */
    double taxRate = taxRatePercentage / 100.0;
    double net = price / (1 + taxRate);
    double tax = net * taxRate;

    cout << fixed << setprecision(2);

    cout << setw(20) << "Item";
    cout << setw(10) << "Net";
    cout << setw(10) << "Tax";
    cout << endl;

    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    
    cout << setw(20) << desc;
    cout << setw(10) << net;
    cout << setw(10) << tax;
    cout << endl;
   
    return 0;
}