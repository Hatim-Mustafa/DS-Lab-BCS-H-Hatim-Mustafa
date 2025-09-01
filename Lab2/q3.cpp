#include <iostream>
using namespace std;

int main () {
    int** arr;
    int students;
    int* courses;

    cin >> students;

    arr = new int*[students];
    courses = new int[students];

    for (int i = 0; i < students; i++) {
        cout << "How many courses for student " << i+1 << ": ";
        cin >> courses[i];
        arr[i] = new int[courses[i]];
        for (int j = 0; j < courses[i]; j++) {
            cout << "Marks for Student " << i+1 << " ,Course " << j+1 << ": ";
            cin >> arr[i][j];
        }
    }
    
    cout << endl;

    int sum = 0;
    
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < courses[i]; j++) {
            sum += arr[i][j];
        }
        cout << "Average for Student " << i+1 << ": " << (float)sum/courses[i];
        cout << endl;
        sum = 0;
    }

    for (int i = 0; i < students; i++) {
        delete [] arr[i];
        
    }
    delete [] arr;
    delete [] courses;
}