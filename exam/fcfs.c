#include <stdio.h>

int main() {
    int n, i, j;
    int at[10], bt[10], wt[10], tat[10], pid[10];
    int time;

    printf("Enter n: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;

        printf("\nP%d\n", pid[i]);

        printf("AT: ");
        scanf("%d", &at[i]);

        printf("BT: ");
        scanf("%d", &bt[i]);
    }

    // Sort by Arrival Time
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                int t;

                t = at[i]; at[i] = at[j]; at[j] = t;
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = pid[i]; pid[i] = pid[j]; pid[j] = t;
            }
        }
    }

    // Calculate WT
    time = at[0];
    wt[0] = 0;
    time += bt[0];

    for(i = 1; i < n; i++) {
        if(time < at[i]) {
            time = at[i];
        }

        wt[i] = time - at[i];
        time += bt[i];
    }

    // Print Table
    printf("\nProcess AT BT WT TAT\n");

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];

        printf("P%d\t%d %d %d %d\n",pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    // Gantt Chart (No Idle)
    printf("\nGantt Chart:\n|");

    for(i = 0; i < n; i++) {
        printf(" P%d |", pid[i]);
    }

    printf("\n");

    time = at[0];
    printf("%d", time);

    for(i = 0; i < n; i++) {
        if(time < at[i]) {
            time = at[i];
        }

        time += bt[i];
        printf("   %d", time);
    }

    printf("\n");

    return 0;
}