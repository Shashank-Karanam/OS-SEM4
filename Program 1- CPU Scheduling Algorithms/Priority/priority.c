#include <stdio.h>

int main() {
    int n;

    // Step 1: Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Step 2: Declare arrays
    int pid[100], burst_time[100], priority[100];
    int waiting_time[100], turnaround_time[100];

    // Step 3: Input burst time and priority
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Burst Time for Process P%d: ", pid[i]);
        scanf("%d", &burst_time[i]);
        printf("Enter Priority for Process P%d (lower number = higher priority): ", pid[i]);
        scanf("%d", &priority[i]);
    }

    // Step 4: Sort based on priority (ascending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                // Swap burst time
                int temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                // Swap priority
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                // Swap process ID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Step 5: Calculate waiting and turnaround times
    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];

    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // Step 6: Display result
    printf("\nPID\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", pid[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }

    // Step 7: Calculate and print averages
    float total_waiting = 0, total_turnaround = 0;
    for (int i = 0; i < n; i++) {
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_waiting / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_turnaround / n);

    return 0;
}
