#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

Node* reverseKGroup(Node* head, int k) {
    if (k == 1 || head == nullptr) {
        return head;
    }
    Node *curr, *prev, *n, *temphead1, *temphead2;
    temphead1 = nullptr;
    curr = head;
    prev = nullptr;
    n = head->next;
    bool first = true;
    while (curr != nullptr) {
        int i = 0;
        while (i < k && curr != nullptr) {
            if (i == 0) {
                temphead2 = curr;
            }
            if (i == k-1) {
                if (first) {
                    head = curr;
                    first = false;
                }
                else {
                    temphead1 -> next = curr;
                }
                temphead1 = temphead2;
            }
            curr->next = prev;
            prev = curr;
            curr = n;
            if (n!= nullptr) {
                n = n->next;
            }
            i +=1;
        }
    }
    if (temphead1 != nullptr) {
        temphead1->next = prev;
    }
    else {
        head = prev;
    }
    temphead2->next = nullptr;
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main () {
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);
    list1->next->next->next = new Node(4);
    list1->next->next->next->next = new Node(5);


    cout << "List: ";
    printList(list1);

    Node* reversed = reverseKGroup(list1, 2);

    cout << "Reversed List: ";
    printList(reversed);

    freeList(reversed);
}