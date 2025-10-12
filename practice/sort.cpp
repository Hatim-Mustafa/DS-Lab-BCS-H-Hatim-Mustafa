#include <iostream>
using namespace std;

void sort(int** arr) {
    int size = 5;
    for (int i =0; i < size-1; i++) {
        int index = i;
        for (int j = i+1; j < size; j++) {
            if (arr[index][1] < arr[j][1]) {
                index = j;
            }
            else if(arr[index][1] == arr[j][1] && arr[index][0] < arr[j][0]) {
                index = j;
            }
        }
        int temp = arr[index][0];
        arr[index][0] = arr[i][0];
        arr[i][0] = temp;
        temp = arr[index][1];
        arr[index][1] = arr[i][1];
        arr[i][1] = temp;
    }
}

int main () {
    //first column for day, 2nd for month
    int** dates = new int*[5];
    for (int i = 0; i < 5; i++) {
        dates[i] = new int[2];
    }

    dates[0][0] = 9;
    dates[0][1] = 10;
    dates[1][0] = 7;
    dates[1][1] = 10;
    dates[2][0] = 5;
    dates[2][1] = 10;
    dates[3][0] = 15;
    dates[3][1] = 10;
    dates[4][0] = 2;
    dates[4][1] = 10;

    sort(dates);

    for (int i = 0; i < 5; i++) {
        cout << dates[i][0] << " " << dates[i][1] << endl;
    }
}