#include <iostream>
using namespace std;

int main() {
    int d;
    cout << "Enter number of departments: ";
    cin >> d;

    int** salaries = new int*[d];
    int* empCount = new int[d];  

    for (int i = 0; i < d; i++) {
        cout << "\nEnter number of employees in department " << i + 1 << ": ";
        cin >> empCount[i];

        salaries[i] = new int[empCount[i]];  

        for (int j = 0; j < empCount[i]; j++) {
            cout << "Enter salary of employee " << j+1 << " in department " << i+1 << ": ";
            cin >> salaries[i][j];
        }
    }

    cout << endl;

    for (int i = 0; i < d; i++) {
        int highest = salaries[i][0];
        for (int j = 1; j < empCount[i]; j++) {
            if (salaries[i][j] > highest) {
                highest = salaries[i][j];
            }
        }
        cout << "Highest salary in Department " << i + 1 << ": " << highest << endl;
    }

    int bestDept = 0;
    float maxAvg = 0.0;

    for (int i = 0; i < d; i++) {
        float sum = 0;
        for (int j = 0; j < empCount[i]; j++) {
            sum += salaries[i][j];
        }
        float avg = sum / empCount[i];

        if (avg > maxAvg) {
            maxAvg = avg;
            bestDept = i;
        }
    }

    cout << "\nDepartment " << bestDept + 1 << " has the maximum average salary: " << maxAvg << endl;

    for (int i = 0; i < d; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] empCount;
}
