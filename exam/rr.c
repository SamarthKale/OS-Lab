#include <stdio.h>

int main() {
    int n, tq;
    int at[10], bt[10], rem[10], wt[10], tat[10];
    int time = 0, completed = 0;
    int i;

    // Gantt chart storage
    int gantt[100];
    int gantt_time[100];
    int g = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for (i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        rem[i] = bt[i];
        wt[i] = 0;
    }

    while (completed < n) {
        int executed = 0;

        for (i = 0; i < n; i++) {
            if (rem[i] > 0 && at[i] <= time) {
                executed = 1;

                gantt[g] = i + 1;
                gantt_time[g] = time;
                g++;

                if (rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    wt[i] = time - bt[i] - at[i];
                    rem[i] = 0;
                    completed++;
                }
            }
        }

        if (!executed)
            time++;
    }

    // Final Gantt entry
    gantt_time[g] = time;

    printf("\n\n🔹 GANTT CHART:\n");
    for (i = 0; i < g; i++) {
        printf("P%d\t", gantt[i]);
    }
    printf("\n0\t");
    for (i = 1; i <= g; i++) {
        printf("%d\t", gantt_time[i - 1]);
    }

    // Turnaround time
    printf("\n\nProcess  AT  BT  WT  TAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        printf("P%d\t  %d   %d   %d   %d\n",
               i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}