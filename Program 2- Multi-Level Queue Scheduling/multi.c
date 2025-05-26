#include <stdio.h>

#define MAX 100

int main() {
    int n, i;
    int bt[MAX], at[MAX], wt[MAX], tat[MAX], type[MAX];
    int sys_bt[MAX], sys_at[MAX], sys_wt[MAX], sys_tat[MAX], sys_n = 0;
    int user_bt[MAX], user_at[MAX], user_wt[MAX], user_tat[MAX], user_n = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    // Input all processes
    for(i = 0; i < n; i++) {
        printf("\nEnter details for Process %d", i+1);
        printf("\nArrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Type (0 = System, 1 = User): ");
        scanf("%d", &type[i]);

        if(type[i] == 0) { // System process
            sys_bt[sys_n] = bt[i];
            sys_at[sys_n] = at[i];
            sys_n++;
        } else { // User process
            user_bt[user_n] = bt[i];
            user_at[user_n] = at[i];
            user_n++;
        }
    }

    int time = 0;

    printf("\n\n--- SYSTEM PROCESSES (High Priority) ---\n");

    for(i = 0; i < sys_n; i++) {
        if(time < sys_at[i])
            time = sys_at[i];
        sys_wt[i] = time - sys_at[i];
        time += sys_bt[i];
        sys_tat[i] = sys_wt[i] + sys_bt[i];

        printf("Process %d: AT = %d, BT = %d, WT = %d, TAT = %d\n",
            i+1, sys_at[i], sys_bt[i], sys_wt[i], sys_tat[i]);
    }

    printf("\n--- USER PROCESSES (Low Priority) ---\n");

    for(i = 0; i < user_n; i++) {
        if(time < user_at[i])
            time = user_at[i];
        user_wt[i] = time - user_at[i];
        time += user_bt[i];
        user_tat[i] = user_wt[i] + user_bt[i];

        printf("Process %d: AT = %d, BT = %d, WT = %d, TAT = %d\n",
            i+1, user_at[i], user_bt[i], user_wt[i], user_tat[i]);
    }

    return 0;
}
