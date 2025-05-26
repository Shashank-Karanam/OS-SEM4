#include <stdio.h>

#define MAX 10

struct Task {
    int id;
    int execution_time;
    int period;
    int next_release;
    int remaining_time;
};

void sortByPeriod(struct Task tasks[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (tasks[i].period > tasks[j].period) {
                struct Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
}

int lcm(int a, int b) {
    int max = (a > b) ? a : b;
    while (1) {
        if (max % a == 0 && max % b == 0)
            return max;
        max++;
    }
}

int getHyperPeriod(struct Task tasks[], int n) {
    int result = tasks[0].period;
    for (int i = 1; i < n; i++)
        result = lcm(result, tasks[i].period);
    return result;
}

int main() {
    int n;
    struct Task tasks[MAX];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("Enter execution time and period for Task %d: ", i + 1);
        scanf("%d %d", &tasks[i].execution_time, &tasks[i].period);
        tasks[i].remaining_time = 0;
        tasks[i].next_release = 0;
    }

    sortByPeriod(tasks, n);
    int hyperPeriod = getHyperPeriod(tasks, n);

    printf("\nScheduling from time 0 to %d:\n", hyperPeriod - 1);
    for (int t = 0; t < hyperPeriod; t++) {
        int scheduled = 0;

        for (int i = 0; i < n; i++) {
            if (t == tasks[i].next_release) {
                tasks[i].remaining_time = tasks[i].execution_time;
                tasks[i].next_release += tasks[i].period;
            }
        }

        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining_time > 0) {
                printf("Time %2d: Task %d is running\n", t, tasks[i].id);
                tasks[i].remaining_time--;
                scheduled = 1;
                break;
            }
        }

        if (!scheduled)
            printf("Time %2d: CPU is idle\n", t);
    }

    return 0;
}
