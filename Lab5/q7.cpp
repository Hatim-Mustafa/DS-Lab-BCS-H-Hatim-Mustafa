#include <iostream>
using namespace std;

void printBoard(int*& queens, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (queens[i] == j) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << "-------------------" << endl;
}

bool isSafe(int*& queens, int row, int col) {
    for (int i = 0; i < row; i++) {
        int qCol = queens[i];
        if (qCol == col || abs(qCol - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve(int*& queens, int row, int n, int& solCount) {
    if (row == n) {
        solCount++;
        printBoard(queens, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(queens, row, col)) {
            queens[row] = col; 
            solve(queens, row + 1, n, solCount);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    int* queens = new int[n];
    int solCount = 0;

    solve(queens, 0, n, solCount);

    cout << solCount << " possible solutions" << endl;

    delete [] queens;
}
