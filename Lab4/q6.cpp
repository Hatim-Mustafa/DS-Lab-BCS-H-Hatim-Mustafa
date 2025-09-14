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
    int count = 0;
    float shrink = 1.3;
    int gap = size;
    bool swapped = true;

    printArray(arr, size);

    while (gap > 1 || swapped) {
        gap = (int)(gap/shrink);
        if (gap < 1) {
            gap = 1;
        }
         
        swapped = false;

        for (int j = 0; j + gap < size; j++) {
            if (arr[j] > arr[j + gap]) {
                int temp = arr[j];
                arr[j] = arr[j + gap];
                arr[j + gap] = temp;
                swapped = true;
                count++;
            }
        }
    }

    printArray(arr, size);
    cout << "Number of swaps: " << count << endl;
}
