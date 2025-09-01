#include <iostream>
#include <string>
using namespace std;

int main() {
    int categories;
    cout << "Enter number of categories: ";
    cin >> categories;

    string* categoryNames = new string[categories];

    int** books = new int*[categories];
    int* bookCounts = new int[categories];

    for (int i = 0; i < categories; i++) {
        cout << "\nEnter name of category " << i + 1 << ": ";
        cin >> categoryNames[i];

        cout << "Enter number of books in " << categoryNames[i] << ": ";
        cin >> bookCounts[i];

        books[i] = new int[bookCounts[i]]; 

        cout << "Enter " << bookCounts[i] << " book IDs:\n";
        for (int j = 0; j < bookCounts[i]; j++) {
            cin >> books[i][j];
        }
    }

    int searchID;
    cout << "\nEnter Book ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < bookCounts[i]; j++) {
            if (books[i][j] == searchID) {
                cout << "Book ID " << searchID << " found in category: " 
                     << categoryNames[i] << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "Book ID " << searchID << " not found in library." << endl;
    }

    for (int i = 0; i < categories; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] bookCounts;
    delete[] categoryNames;
}
