#include <stdio.h>
#include <stdlib.h>

// Enum to represent the color of a Red-Black Tree node
enum Color {
    RED,
    BLACK
};

// Structure to represent a Red-Black Tree node
struct Node {
    int data;
    enum Color color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

// Create a new Red-Black Tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->color = RED;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Function to perform left rotation on a Red-Black Tree
void leftRotate(struct Node** root, struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Function to perform right rotation on a Red-Black Tree
void rightRotate(struct Node** root, struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

// Function to fix the Red-Black Tree after insertion
void insertFixup(struct Node** root, struct Node* z) {
    while (z != *root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            struct Node* y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            struct Node* y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

// Function to insert a node into a Red-Black Tree
void insert(struct Node** root, int data) {
    struct Node* z = createNode(data);
    struct Node* y = NULL;
    struct Node* x = *root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == NULL) {
        *root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }
    insertFixup(root, z);
}

// Function to perform an in-order traversal of a Red-Black Tree
void inOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d(%s) ", root->data, (root->color == RED) ? "RED" : "BLACK");
    inOrder(root->right);
}

int main() {
    struct Node* root = NULL;

    int keys[] = {10, 20, 5, 8, 30, 3, 25};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(&root, keys[i]);
    }

    printf("Red-Black Tree keys (Color): ");
    inOrder(root);
    printf("\n");

    return 0;
}
