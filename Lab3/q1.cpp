#include <iostream>
using namespace std;

struct Node {
    char value;
    Node* next;
};

bool isPalindrome (Node* head) {
    Node* slow;
    Node* fast;
    slow = head;
    fast = head->next;
    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != nullptr) {
            fast = fast->next;
        }
    }

    Node* prev = nullptr;
    Node* curr = slow->next;
    Node* n = curr->next;

    while(curr != nullptr) {
        curr->next = prev;
        prev = curr;
        curr = n;
        if (n != nullptr) {
            n = n->next;
        }
    }
    
    Node* second = prev;
    
    while (second != nullptr) {
        if (second->value != head->value) {
            return false;
        }
        head = head->next;
        second = second->next;
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
    head = head->next;
    head->value = 'D';
    head->next = new Node();
    head = head->next;
    head->value = 'A';
    head->next = new Node();
    head = head->next;
    head->value = 'M';
    head->next = nullptr;

    if (isPalindrome(start)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}