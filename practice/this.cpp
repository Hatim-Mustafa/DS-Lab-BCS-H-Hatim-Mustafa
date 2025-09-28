#include <iostream>
using namespace std;

void sort (int** arr, int n) {
    int len = n*n;

    for (int i = 0; i < len-1; i++) {
        int index = i;
        for (int j = i+1; j < len; j++) {
            if (arr[j%n][j/n] < arr[index%n][index/n]) {
                index = j;
            }
        }
        int temp = arr[i%n][i/n];
        arr[i%n][i/n] = arr[index%n][index/n];
        arr[index%n][index/n] = temp;
    }
}

void printArray (int** arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main () {
    int n = 4;
    int** arr = new int*[n];
    int init[4][4] = {{2,3,2,8},{9,4,54,5},{1,7,4,11},{6,1,9,2}};
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = init[i][j];
        }
    }
    printArray(arr, 4);
    sort(arr, 4);
    cout << endl;
    printArray(arr, 4);

    for (int i = 0; i < n; i++) delete[] arr[i];
    delete[] arr;
}