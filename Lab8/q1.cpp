#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* mother;
    Node* father;
    Node(string n) : name(n), mother(nullptr), father(nullptr) {};
};

void displayLeafNodes (Node* root) {
    if(root->mother == nullptr && root->father == nullptr) {
        cout << root->name << endl;
    }
    else {
        displayLeafNodes(root->mother);
        displayLeafNodes(root->father);
    }
}

int calculateHeight (Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int h = max(calculateHeight(root->mother), calculateHeight(root->father)) + 1;
    return h;
}

int printLevels (Node* root) {
    if(root->mother == nullptr && root->father == nullptr) {
        cout << root->name << ":" << 0 << endl;
        return 0;
    }
    else {
        int l = max(printLevels(root->mother), printLevels(root->father)) + 1;
        cout << root->name << ":" << l << endl;
        return l;
    }
}

int main () {
    Node* youngest = new Node("Aslam");
    youngest->mother = new Node("Maryam");
    youngest->father = new Node("Khalid");
    youngest->mother->father = new Node("Akram");
    youngest->mother->mother = new Node("Laiba");
    youngest->father->father = new Node("Minhas");
    youngest->father->mother = new Node("Kulsum");

    cout << youngest->name << endl;
    cout << endl;
    displayLeafNodes(youngest);
    cout << endl;
    cout << calculateHeight(youngest) << endl << endl;
    printLevels(youngest);
}