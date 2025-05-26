#include <stdio.h>

int main() {
    int n, tq, i, time = 0, remain;
    int bt[10], rt[10], wt[10], tat[10];
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;

    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int done;
    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = 0;
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while(!done);

    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
    
    return 0;
}
