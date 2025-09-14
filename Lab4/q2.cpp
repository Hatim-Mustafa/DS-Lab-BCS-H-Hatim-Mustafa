#include <iostream>
using namespace std;

void printArray (int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main () {
    int arr[] = {15,52,33,34,5,86,67,18,92};

    int size = 9;
    int count = 0;

    printArray(arr, size);

    int n = 9;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
        n -= 1;
    }

    printArray(arr, size);
    cout << "Number of swaps: " << count << endl;
}