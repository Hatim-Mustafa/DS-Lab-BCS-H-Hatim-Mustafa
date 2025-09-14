#include <iostream>
using namespace std;

void printArray (int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int binarySearch (int* arr, int num, int max, int min) {
    int high = max;
    int low = min;
    int mid = (high+low)/2;
    if (low >= high) {
        return -1;
    }
    if (arr[mid] == num) {
        return mid;
    }
    else if (num > arr[mid]) {
        return binarySearch(arr, num, high, mid+1);
    }
    else {
        return binarySearch(arr, num, mid-1, low);
    }
}

int main () {
    int arr[] = {15,52,33,34,5,86,67,18,92};

    int size = 9;

    printArray(arr, size);

    for (int i = 1; i < size; i++) {
        int value = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > value) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = value;
    }

    printArray(arr, size);

    int num = 67;
    int index = binarySearch(arr, num, size-1, 0);
    if (index == -1) {
        cout << num << " is not present\n";
    }
    else {
        cout << num << " is present at index " << index << endl;
    }
}
