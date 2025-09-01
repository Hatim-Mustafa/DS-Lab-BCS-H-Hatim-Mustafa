#include <iostream>
using namespace std;

struct Node {
    char value;
    Node* next;
};

bool isPalindrome (Node* head) {
    Node* temp = head;
    // Node* slow, fast;
    // slow = head;
    // fast = head;
    // while (fast->next != null) {
    //     slow = slow->next;
    //     fast = fast->next;
    //     fast = fast->next;
    // }
    int length = 0;
    while (head->next != nullptr) {
        length += 1;
        head = head->next;
    }
    head = temp;
    string s1;
    string s2;
    if (length%2 == 0) {
        for (int i = 0; i < length/2; i++) {
            s1 += head->value;
            head = head->next;
        }
        for (int i = 0; i < length/2; i++) {
            s2+= head->value;
            head = head->next;
        }
    }
    else {
        for (int i = 0; i < length/2; i++) {
            s1 += head->value;
            head = head->next;
        }
        head = head->next;
        for (int i = 0; i < length/2; i++) {
            s2+= head->value;
            head = head->next;
        }
    }
    for (int i = 0; i < length/2; i++) {
        if (s1[i] != s2[(length/2)-1-i]) {
            return false;
        }
    }
    return true;
}

int main () {
    Node* head = new Node();
    Node* start = head;
    head->value = 'M';
    head->next = new Node();
    head = head->next;
    head->value = 'A';
    head->next = new Node();
    // head = head->next;
    // head->value = 'D';
    // head->next = new Node();
    head = head->next;
    head->value = 'A';
    head->next = new Node();
    head = head->next;
    head->value = 'M';
    head->next = new Node();
    head = head->next;

    if (isPalindrome(start)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}