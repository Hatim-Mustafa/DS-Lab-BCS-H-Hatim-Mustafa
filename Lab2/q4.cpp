#include <iostream>
using namespace std;

int main () {
    float* expenses;
    int months;

    cout << "Enter number of months: ";
    cin >> months;

    expenses = new float[months];

    for (int i = 0; i < months; i++) {
        cout << "Enter expense for month " << i + 1 << ": ";
        cin >> expenses[i];
    }

    int n;

    cout << "Enter new number of months: ";
    cin >> n;

    float* temp = new float[n];
    for (int i = 0; i < months; i++) {
        temp[i] = expenses[i];
    }
    delete [] expenses;
    expenses = temp;

    for (int i = 0; i < (n - months); i++) {
        cout << "Enter expense for month " << months + i + 1 << ": ";
        cin >> expenses[months + i];
    }
    months = n;
    
    cout << endl;

    float sum = 0;
    for (int i = 0; i < months; i++) {
        sum += expenses[i];
    }
    cout << "Total expense: " << sum << endl;
    cout << "Average expense: " << sum/months << endl;

    delete [] expenses;
}