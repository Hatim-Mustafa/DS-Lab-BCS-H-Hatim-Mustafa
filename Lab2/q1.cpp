#include <iostream>
using namespace std;

int main () {
    int* arr;
    int num;

    cin >> num;

    arr = new int[num];

    for (int i = 0; i < num; i++) {
        arr[i] = 0;
    }

    int index;
    cin >> index;
    cin >> arr[index];

    cin >> index;
    cin >> arr[index];
    
    cout << endl;

    for (int i = 0; i < num; i++) {
        cout << arr[i] << endl;
    }

    delete [] arr;
}