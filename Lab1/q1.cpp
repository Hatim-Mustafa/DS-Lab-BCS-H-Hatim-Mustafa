#include <iostream>
using namespace std;

class BankAccount {
public:
    float balance;

    BankAccount() {
        balance = 0;
    }

    BankAccount(float i) {
        balance = i;
    }

    BankAccount(BankAccount& other) {
        balance = other.balance;
    }

};

int main() {
    BankAccount account1;
    cout << "Balance of account1 : " << account1.balance << endl;

    BankAccount account2(1000);
    cout << "Balance of account2 : " << account2.balance << endl;

    BankAccount account3(account2); 
    account3.balance -= 200; 
    cout << "Balance of account3 : " << account3.balance << endl;
    cout << "Balance of account2 : " << account2.balance << endl;
}