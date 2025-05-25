#include <stdio.h>

int main() {
    int n, i;
    int burstTime[100], arrivalTime[100];
    int completionTime[100], turnaroundTime[100], waitingTime[100];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    }

    // Sort by arrival time
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrivalTime[i] > arrivalTime[j]) {
                // Swap arrival times
                int temp = arrivalTime[i];
                arrivalTime[i] = arrivalTime[j];
                arrivalTime[j] = temp;

                // Swap burst times
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i == 0)
            completionTime[i] = arrivalTime[i] + burstTime[i];
        else
            completionTime[i] = (completionTime[i - 1] > arrivalTime[i] ? completionTime[i - 1] : arrivalTime[i]) + burstTime[i];

        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTime[i], burstTime[i], completionTime[i], turnaroundTime[i], waitingTime[i]);
    }

    return 0;
}
