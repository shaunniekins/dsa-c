#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Pre-order traversal (root -> left -> right)
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// In-order traversal (left -> root -> right)
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Post-order traversal (left -> right -> root)
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Function to find the height of a binary tree
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// Level-order traversal using a queue
void levelOrder(struct Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}

// Function to print nodes at a specific level
void printLevel(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    printf("Level-order traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
