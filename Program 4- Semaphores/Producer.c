#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;
int mutex = 1;      // binary semaphore for mutual exclusion
int full = 0;       // number of full slots
int empty = SIZE;   // number of empty slots

// Simulate semaphore wait and signal
int wait(int s) {
    return (--s);
}

int signal(int s) {
    return (++s);
}

void producer() {
    if (empty == 0) {
        printf("Buffer is Full. Producer waits...\n");
        return;
    }
    if (mutex == 1) {
        mutex = wait(mutex);
        empty = wait(empty);
        full = signal(full);

        int item = rand() % 100;
        buffer[in] = item;
        printf("Produced: %d at %d\n", item, in);
        in = (in + 1) % SIZE;

        mutex = signal(mutex);
    }
}

void consumer() {
    if (full == 0) {
        printf("Buffer is Empty. Consumer waits...\n");
        return;
    }
    if (mutex == 1) {
        mutex = wait(mutex);
        full = wait(full);
        empty = signal(empty);

        int item = buffer[out];
        printf("Consumed: %d from %d\n", item, out);
        out = (out + 1) % SIZE;

        mutex = signal(mutex);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Producer-Consumer Menu ---\n");
        printf("1. Produce\n2. Consume\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: producer(); break;
            case 2: consumer(); break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
