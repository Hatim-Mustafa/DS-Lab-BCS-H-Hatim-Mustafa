#include <iostream>
using namespace std;

struct Node {
    int playCount;
    Node* left;
    Node* right;
    Node(int item)
    {
        playCount = item;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int x)
{

    Node* temp = new Node(x);

    if (root == NULL)
        return temp;

    Node *parent = NULL, *curr = root;
    while (curr != NULL) {
        parent = curr;
        if (curr->playCount > x)
            curr = curr->left;
        else if (curr->playCount < x)
            curr = curr->right;
        else
            return root;
    }

    if (parent->playCount > x)
        parent->left = temp;
    else
        parent->right = temp;
    return root;
}

void inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->playCount << " ";
        inorder(root->right);
    }
}

void postorder(Node* root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->playCount << " ";
    }
}

Node* getSuccessor(Node* curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node* delNode(Node* root, int x)
{

    if (root == NULL)
        return root;

    if (root->playCount > x)
        root->left = delNode(root->left, x);
    else if (root->playCount < x)
        root->right = delNode(root->right, x);

    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* succ = getSuccessor(root);
        root->playCount = succ->playCount;
        root->right = delNode(root->right, succ->playCount);
    }
    return root;
}


int main() {

    Node* root = new Node(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);
    cout << endl;
    postorder(root);
    delNode(root, 30);

    cout << endl;
    inorder(root);

    return 0;
}