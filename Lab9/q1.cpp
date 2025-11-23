#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k): key(k), left(nullptr), right(nullptr), height(1) {}
};

int height (Node * node){

    if(node == NULL)
    return 0;

    else{
        int h_left= height(node->left);
        int h_right = height (node ->right);
        if (h_left > h_right)
        return (h_left + 1);
        else return ( h_right + 1);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key) {
    if (node == nullptr) {
        cout << "Inserted node with value: " << key << endl;
        return new Node(key);
    }
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);


    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        cout << "Performed right rotation\n";
        return rightRotate(node);
    }
    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        cout << "Performed left rotation\n";
        return leftRotate(node);
    }
    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        cout << "Performed left rotation\n";
        cout << "Performed right rotation\n";
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        cout << "Performed right rotation\n";
        cout << "Performed left rotation\n";
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;

            delete temp;
        }
        else {
            Node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0) {
        cout << "Performed right rotation\n";
        return rightRotate(root);
    }
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        cout << "Performed left rotation\n";
        cout << "Performed right rotation\n";
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0) {
        cout << "Performed left rotation\n";
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        cout << "Performed right rotation\n";
        cout << "Performed left rotation\n";
        return leftRotate(root);
    }

    return root;
}


int main() {
    Node *root = nullptr;
    root = insert(root, 673);
    cout << root->height << endl;
    root = insert(root, 977);
    cout << root->height << endl;
    root = insert(root, 699);
    cout << root->height << endl;
    root = insert(root, 690);
    cout << root->height << endl;
    root = insert(root, 576);
    cout << root->height << endl;
    root = insert(root, 500);
    cout << root->height << endl;
    root = insert(root, 549);
    cout << root->height << endl;

    root = deleteNode(root, 690);
    cout << root->height << endl;
    root = deleteNode(root, 673);
    cout << root->height << endl;
    root = deleteNode(root, 500);
    cout << root->height << endl;
}