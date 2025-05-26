#include <stdio.h>
#include <stdlib.h>

#define NUM_PHILOSOPHERS 5

// Philosopher states: 0 = Thinking, 1 = Hungry, 2 = Eating
int dp_state[NUM_PHILOSOPHERS] = {0};
int forks[NUM_PHILOSOPHERS] = {1, 1, 1, 1, 1}; // 1 = available, 0 = in use

void take_forks(int p) {
    if (forks[p] && forks[(p + 1) % NUM_PHILOSOPHERS]) {
        forks[p] = forks[(p + 1) % NUM_PHILOSOPHERS] = 0;
        dp_state[p] = 2; // Eating
        printf("Philosopher %d is Eating using forks %d and %d\n", p, p, (p + 1) % NUM_PHILOSOPHERS);
    } else {
        dp_state[p] = 1; // Hungry
        printf("Philosopher %d is Hungry but forks are not available\n", p);
    }
}

void put_forks(int p) {
    if (dp_state[p] == 2) {
        forks[p] = forks[(p + 1) % NUM_PHILOSOPHERS] = 1;
        dp_state[p] = 0; // Thinking
        printf("Philosopher %d has put down forks %d and %d and is Thinking\n", p, p, (p + 1) % NUM_PHILOSOPHERS);
    } else {
        printf("Philosopher %d was not Eating, cannot put forks down\n", p);
    }
}

void print_states() {
    printf("\nCurrent States:\n");
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        printf("Philosopher %d: ", i);
        if (dp_state[i] == 0) printf("Thinking\n");
        else if (dp_state[i] == 1) printf("Hungry\n");
        else if (dp_state[i] == 2) printf("Eating\n");
    }
}

void run_dining_philosophers() {
    int choice, p;

    while (1) {
        printf("\n--- Dining Philosophers Menu ---\n");
        printf("1. Philosopher tries to Eat\n");
        printf("2. Philosopher puts down forks\n");
        printf("3. Show current states\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter philosopher number (0 to 4): ");
                scanf("%d", &p);
                if (p >= 0 && p < NUM_PHILOSOPHERS)
                    take_forks(p);
                else
                    printf("Invalid philosopher number!\n");
                break;

            case 2:
                printf("Enter philosopher number (0 to 4): ");
                scanf("%d", &p);
                if (p >= 0 && p < NUM_PHILOSOPHERS)
                    put_forks(p);
                else
                    printf("Invalid philosopher number!\n");
                break;

            case 3:
                print_states();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
int main() {
    run_dining_philosophers();
    return 0;
}
