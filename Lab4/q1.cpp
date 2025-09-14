#include <iostream>
using namespace std;

int main () {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int index = -1;
    int valueToBeFound = 6;

    for (int i = 0; i < 9; i++) {
        if (arr[i] == valueToBeFound) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << valueToBeFound << " is at index " << index << endl;
    }
    else {
        cout << valueToBeFound << " not in the list\n";
    }
    
}