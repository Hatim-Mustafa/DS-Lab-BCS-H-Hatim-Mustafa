#include <iostream>
using namespace std;

void printArray (int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int interpolationSearch (int* arr, int num, int max, int min) {
    int high = max;
    int low = min;
    if (low == high) {
        if (arr[low] == num) {return low;}
        return -1;
    }
    int pos = low + ((num - arr[low])*(high-low))/(arr[high]-arr[low]);
    if (arr[pos] == num) {
        return pos;
    }
    else if (num > arr[pos]) {
        return interpolationSearch(arr, num, high, pos+1);
    }
    else {
        return interpolationSearch(arr, num, pos-1, low);
    }
}

int main () {
    int arr[] = {5,11,14,22,30,32,38,44,50};

    int size = 9;

    printArray(arr, size);

    int num = 30;
    int index = interpolationSearch(arr, num, size-1, 0);
    if (index == -1) {
        cout << num << " is not present\n";
    }
    else {
        cout << num << " is present at index " << index << endl;
    }
}
