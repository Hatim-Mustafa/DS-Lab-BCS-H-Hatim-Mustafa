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

    printArray(arr, size);

    for (int i = 0; i < size-1; i++) {
        int index = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    printArray(arr, size);
}