#include <iostream>
#include <climits>   // for INT_MIN and INT_MAX
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* newNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->left = temp->right = nullptr;
    return temp;
}

// Utility function to check BST property
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

    // Node value must be within (minVal, maxVal)
    if (root->data <= minVal || root->data >= maxVal)
        return false;

    // Recursively check subtrees
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

// Main function to check if binary tree is BST
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    if (isBST(root))
        cout << "The given tree is a Binary Search Tree (BST)" << endl;
    else
        cout << "The given tree is NOT a Binary Search Tree" << endl;

    return 0;
}
