#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Structure to represent a key-value pair in the hash table
struct KeyValuePair {
    int key;
    int value;
    struct KeyValuePair* next;
};

// Structure to represent a hash table
struct HashTable {
    struct KeyValuePair* table[TABLE_SIZE];
};

// Function to create and initialize a hash table
struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Function to calculate the hash value for a given key
int hash(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable* hashTable, int key, int value) {
    int index = hash(key);
    struct KeyValuePair* newPair = (struct KeyValuePair*)malloc(sizeof(struct KeyValuePair));
    newPair->key = key;
    newPair->value = value;
    newPair->next = NULL;

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newPair;
    } else {
        struct KeyValuePair* current = hashTable->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPair;
    }
}

// Function to retrieve a value from the hash table given a key
int get(struct HashTable* hashTable, int key) {
    int index = hash(key);
    struct KeyValuePair* current = hashTable->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Key not found
}

int main() {
    struct HashTable* hashTable = createHashTable();

    insert(hashTable, 5, 100);
    insert(hashTable, 15, 200);
    insert(hashTable, 25, 300);

    int keyToFind = 15;
    int foundValue = get(hashTable, keyToFind);

    if (foundValue != -1) {
        printf("Value for key %d: %d\n", keyToFind, foundValue);
    } else {
        printf("Key %d not found in the hash table.\n", keyToFind);
    }

    return 0;
}
