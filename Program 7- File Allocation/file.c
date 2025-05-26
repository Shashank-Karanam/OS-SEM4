#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int memory[SIZE]; // 0 - free, 1 - occupied

// Function to initialize memory
void initializeMemory() {
    for (int i = 0; i < SIZE; i++)
        memory[i] = 0;
}

// Sequential Allocation
void sequentialAllocation() {
    int start, length;
    printf("Enter starting block and length of the file: ");
    scanf("%d %d", &start, &length);

    int available = 1;
    for (int i = start; i < start + length; i++) {
        if (memory[i] == 1 || i >= SIZE) {
            available = 0;
            break;
        }
    }

    if (available) {
        for (int i = start; i < start + length; i++)
            memory[i] = 1;

        printf("File allocated at blocks: ");
        for (int i = start; i < start + length; i++)
            printf("%d ", i);
        printf("\n");
    } else {
        printf("Blocks not available.\n");
    }
}

// Indexed Allocation
void indexedAllocation() {
    int indexBlock, n, blocks[50];
    printf("Enter index block and number of blocks needed: ");
    scanf("%d %d", &indexBlock, &n);

    if (memory[indexBlock] == 1) {
        printf("Index block already allocated.\n");
        return;
    }

    int success = 1;
    for (int i = 0; i < n; i++) {
        printf("Enter block number %d: ", i + 1);
        scanf("%d", &blocks[i]);
        if (memory[blocks[i]] == 1 || blocks[i] >= SIZE) {
            success = 0;
        }
    }

    if (success) {
        memory[indexBlock] = 1;
        for (int i = 0; i < n; i++)
            memory[blocks[i]] = 1;

        printf("File allocated using indexed allocation.\nIndex block: %d\nBlocks: ", indexBlock);
        for (int i = 0; i < n; i++)
            printf("%d ", blocks[i]);
        printf("\n");
    } else {
        printf("One or more blocks already allocated or invalid.\n");
    }
}

// Linked Allocation
void linkedAllocation() {
    int n, block;
    printf("Enter number of blocks needed: ");
    scanf("%d", &n);

    int blocks[50];
    int success = 1;
    for (int i = 0; i < n; i++) {
        printf("Enter block number %d: ", i + 1);
        scanf("%d", &blocks[i]);

        if (memory[blocks[i]] == 1 || blocks[i] >= SIZE)
            success = 0;
    }

    if (success) {
        for (int i = 0; i < n; i++)
            memory[blocks[i]] = 1;

        printf("File allocated using linked allocation.\nBlocks: ");
        for (int i = 0; i < n; i++) {
            printf("%d", blocks[i]);
            if (i != n - 1)
                printf(" -> ");
        }
        printf("\n");
    } else {
        printf("One or more blocks already allocated or invalid.\n");
    }
}

int main() {
    int choice;
    initializeMemory();

    while (1) {
        printf("\n--- File Allocation Strategies ---\n");
        printf("1. Sequential Allocation\n");
        printf("2. Indexed Allocation\n");
        printf("3. Linked Allocation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sequentialAllocation();
                break;
            case 2:
                indexedAllocation();
                break;
            case 3:
                linkedAllocation();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
