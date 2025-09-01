#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter number of readings per day: ";
    cin >> m;

    float** temps = new float*[n];
    for (int i = 0; i < n; i++) {
        temps[i] = new float[m];
    }

    for (int i = 0; i < n; i++) {
        cout << "\nEnter " << m << " temperature readings for Day " << i + 1 << ":\n";
        for (int j = 0; j < m; j++) {
            cin >> temps[i][j];
        }
    }

    float* dailyAvg = new float[n];
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < m; j++) {
            sum += temps[i][j];
        }
        dailyAvg[i] = sum / m;
        cout << "Average temperature of Day " << i + 1 << ": "
             << dailyAvg[i] << endl;
    }

    int hottestDay = 0, coldestDay = 0;
    for (int i = 1; i < n; i++) {
        if (dailyAvg[i] > dailyAvg[hottestDay]) hottestDay = i;
        if (dailyAvg[i] < dailyAvg[coldestDay]) coldestDay = i;
    }

    cout << "\nHottest Day = Day " << hottestDay + 1
         << " with avg temp " << dailyAvg[hottestDay] << endl;
    cout << "Coldest Day = Day " << coldestDay + 1
         << " with avg temp " << dailyAvg[coldestDay] << endl;

    for (int i = 0; i < n; i++) {
        delete[] temps[i];
    }
    delete[] temps;
    delete[] dailyAvg;
}
