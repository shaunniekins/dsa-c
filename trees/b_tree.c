#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 3

// Structure to represent a B-tree node
struct BTreeNode {
    int keys[MAX_KEYS];
    struct BTreeNode* children[MAX_KEYS + 1];
    int numKeys;
    int isLeaf;
};

// Function to create a new B-tree node
struct BTreeNode* createNode(int isLeaf) {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    newNode->numKeys = 0;
    newNode->isLeaf = isLeaf;
    for (int i = 0; i <= MAX_KEYS; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to split a full child of a B-tree node
void splitChild(struct BTreeNode* parent, int childIndex, struct BTreeNode* child) {
    struct BTreeNode* newNode = createNode(child->isLeaf);
    struct BTreeNode* sibling = parent->children[childIndex + 1];

    // Move the middle key of the child to the parent node
    parent->keys[parent->numKeys] = child->keys[MAX_KEYS / 2];
    parent->numKeys++;

    // Move keys and children from the full child to the new node
    for (int i = 0; i < MAX_KEYS / 2; i++) {
        newNode->keys[i] = child->keys[i + MAX_KEYS / 2 + 1];
        child->keys[i + MAX_KEYS / 2 + 1] = 0;
    }

    if (!child->isLeaf) {
        for (int i = 0; i < MAX_KEYS / 2 + 1; i++) {
            newNode->children[i] = child->children[i + MAX_KEYS / 2 + 1];
            child->children[i + MAX_KEYS / 2 + 1] = NULL;
        }
    }

    // Adjust the number of keys in child and the new node
    child->numKeys = MAX_KEYS / 2;
    newNode->numKeys = MAX_KEYS / 2;

    // Make space for the new child in the parent node
    for (int i = parent->numKeys; i > childIndex; i--) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[childIndex + 1] = newNode;
}

// Function to insert a key into a B-tree node
void insertNonFull(struct BTreeNode* node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        // Shift keys to make space for the new key
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        // Find the child to insert the key
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }

        i++;
        if (node->children[i]->numKeys == MAX_KEYS) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

// Function to insert a key into a B-tree
struct BTreeNode* insert(struct BTreeNode* root, int key) {
    if (root->numKeys == MAX_KEYS) {
        struct BTreeNode* newNode = createNode(0);
        newNode->children[0] = root;
        splitChild(newNode, 0, root);
        insertNonFull(newNode, key);
        return newNode;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

// Function to print the keys of a B-tree node
void printNode(struct BTreeNode* node) {
    for (int i = 0; i < node->numKeys; i++) {
        printf("%d ", node->keys[i]);
    }
    if (!node->isLeaf) {
        printf("\n");
        for (int i = 0; i <= node->numKeys; i++) {
            printNode(node->children[i]);
        }
    }
}

int main() {
    struct BTreeNode* root = createNode(1); // Create a B-tree with one leaf node

    int keys[] = {10, 20, 5, 8, 30, 3, 25};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }

    printf("B-tree keys: ");
    printNode(root);

    return 0;
}
