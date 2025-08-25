#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* studentName;
    char* examDate;
    int score;

public:
    Exam(char* name, char* date, int s) {
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);

        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);

        score = s;
    }

    void setStudentName(char* name) {
        delete[] studentName;
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
    }

    void setExamDate(char* date) {
        delete[] examDate;
        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);
    }

    void setScore(int s) {
        score = s;
    }

    void display() const {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << score << endl;
    }

    ~Exam() {
        delete[] studentName;
        delete[] examDate;
    }
};

int main() {
    Exam exam1("Alice", "2025-08-15", 85);
    exam1.display();

    Exam exam2 = exam1; 
    exam2.display();

    exam2.setStudentName("Bob");
    exam2.setExamDate("2025-09-01");
    exam2.setScore(90);

    exam2.display();
    exam1.display(); 
}

