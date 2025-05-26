#include <stdio.h>
#define MAX 100

int main() {
    int n, i, j;
    int arrivalTime[MAX], burstTime[MAX], completionTime[MAX], turnaroundTime[MAX], waitingTime[MAX];
    int isCompleted[MAX] = {0}, startTime[MAX], processID[MAX];
    int time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        processID[i] = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    }

    while (completed < n) {
        int idx = -1;
        int minBT = 1e9;

        for (i = 0; i < n; i++) {
            if (arrivalTime[i] <= time && isCompleted[i] == 0) {
                if (burstTime[i] < minBT) {
                    minBT = burstTime[i];
                    idx = i;
                }
                if (burstTime[i] == minBT) {  // Tie-breaking using arrival time
                    if (arrivalTime[i] < arrivalTime[idx]) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            startTime[idx] = time;
            completionTime[idx] = time + burstTime[idx];
            turnaroundTime[idx] = completionTime[idx] - arrivalTime[idx];
            waitingTime[idx] = turnaroundTime[idx] - burstTime[idx];

            time = completionTime[idx];
            isCompleted[idx] = 1;
            completed++;
        } else {
            time++;
        }
    }

    printf("\nP\tAT\tBT\tST\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processID[i], arrivalTime[i], burstTime[i], startTime[i], completionTime[i], turnaroundTime[i], waitingTime[i]);
    }

    return 0;
}
