#include <iostream>
using namespace std;

int main () {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix1;
    int** matrix2;
    int** result;

    matrix1 = new int*[rows];      
    for (int i = 0; i < rows; i++) {
        matrix1[i] = new int[cols];        
    }

    matrix2 = new int*[rows];      
    for (int i = 0; i < rows; i++) {
        matrix2[i] = new int[cols];        
    }

    result = new int*[rows];      
    for (int i = 0; i < rows; i++) {
        result[i] = new int[cols];        
    }

    cout << "Matrix 1\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element (" << i << "," << j << "):";
            cin >> matrix1[i][j];
        }
    }

    cout << "Matrix 2\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element (" << i << "," << j << "):";
            cin >> matrix2[i][j];
        }
    }

    cout << "Addition" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nSubtraction" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    

    for (int i = 0; i < rows; i++) {
        delete[] matrix1[i];                
    }
    delete[] matrix1;  

    for (int i = 0; i < rows; i++) {
        delete[] matrix2[i];                
    }
    delete[] matrix2; 

    for (int i = 0; i < rows; i++) {
        delete[] result[i];                
    }
    delete[] result; 

}