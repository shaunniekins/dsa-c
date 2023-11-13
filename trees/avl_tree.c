#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the AVL tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to create a new AVL tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to get the height of a node
int getHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the balance factor of a node
int getBalanceFactor(struct Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to perform a right rotation
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Function to perform a left rotation
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

// Function to insert a node into the AVL tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else // Duplicate data is not allowed
        return root;

    // Update the height of the current node
    root->height = 1 + (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right));

    // Get the balance factor to check if the tree became unbalanced
    int balance = getBalanceFactor(root);

    // Left Heavy
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // Right Heavy
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // Left Right Heavy
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Heavy
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform an in-order traversal of the AVL tree
void inOrder(struct Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    return 0;
}
