#include <iostream>
using namespace std;

int main () {
    int** arr;
    int benches, seats;

    cin >> benches;
    cin >> seats;

    arr = new int*[benches];

    for (int i = 0; i < benches; i++) {
        arr[i] = new int[seats];
        for (int j = 0; j < seats; j++) {
            arr[i][j] = 0;
        }
    }

    int seat, bench;

    cin >> bench;
    cin >> seat;
    arr[bench][seat] = 1;

    cin >> bench;
    cin >> seat;
    arr[bench][seat] = 1;

    cin >> bench;
    cin >> seat;
    arr[bench][seat] = 1;
    
    cout << endl;
    
    for (int i = 0; i < benches; i++) {
        for (int j = 0; j < seats; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < benches; i++) {
        delete [] arr[i];
        
    }
    delete [] arr;
}