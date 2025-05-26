#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int main() {
    int n, r;
    int allocation[MAX][MAX], max[MAX][MAX], need[MAX][MAX];
    int available[MAX];
    bool finish[MAX] = {false};
    int safe_sequence[MAX];
    int count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &r);

    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &allocation[i][j]);

    printf("\nEnter Max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter Available Resources:\n");
    for (int j = 0; j < r; j++)
        scanf("%d", &available[j]);

    // Calculate Need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > available[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int j = 0; j < r; j++)
                        available[j] += allocation[i][j];

                    safe_sequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) break;
    }

    if (count == n) {
        printf("\nSystem is in a Safe State.\nSafe sequence: ");
        for (int i = 0; i < n; i++)
            printf("P%d ", safe_sequence[i]);
        printf("\n");
    } else {
        printf("\nSystem is NOT in a safe state. Unsafe state detected.\n");
    }

    return 0;
}
