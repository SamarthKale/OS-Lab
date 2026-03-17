#include <stdio.h>

int main() {
    int n, i;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Completion Time
    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++) {
        if (ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];  // CPU idle gap
        else
            ct[i] = ct[i-1] + bt[i];
    }

    // TAT and WT
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];
        avg_wt  += wt[i];
        avg_tat += tat[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], wt[i], tat[i]);

    printf("\nGantt Chart:\n|");
    for (i = 0; i < n; i++)
        printf(" P%d |", i+1);
    printf("\n%d", at[0]);
    for (i = 0; i < n; i++)
        printf("   %d", ct[i]);

    printf("\n\nAvg WT  = %.2f", avg_wt / n);
    printf("\nAvg TAT = %.2f\n", avg_tat / n);

    return 0;
}
