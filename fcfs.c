#include <stdio.h>

int main() {
    int n, i, j, temp;
    int bt[10], at[10], wt[10], tat[10], ct[10], p[10];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Arrival Time for P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort by Arrival Time (FCFS order)
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (at[i] > at[j]) {
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i];  p[i]  = p[j];  p[j]  = temp;
            }

    // Calculate Completion Time
    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++) {
        if (ct[i - 1] < at[i])
            ct[i] = at[i] + bt[i];   // CPU was idle
        else
            ct[i] = ct[i - 1] + bt[i];
    }

    // Calculate WT and TAT
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];
        avg_wt  += wt[i];
        avg_tat += tat[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);

    // Gantt Chart
    printf("\nGantt Chart:\n|");
    for (i = 0; i < n; i++)
        printf(" P%d |", p[i]);

    printf("\n%d", at[0]);
    for (i = 0; i < n; i++)
        printf("   %d", ct[i]);

    printf("\n\nAvg WT  = %.2f", avg_wt / n);
    printf("\nAvg TAT = %.2f\n", avg_tat / n);

    return 0;
}
