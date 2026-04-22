#include <stdio.h>

int main() {
    int n, i, j, temp;
    int bt[10], at[10], wt[10], tat[10], ct[10], p[10];
    int done[10], current_time, min_idx, remaining;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Arrival Time for P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        done[i] = 0;
    }

    current_time = 0;
    int gantt_p[10], gantt_start[10], gantt_end[10];
    int gantt_count = 0;

    for (int count = 0; count < n; count++) {
        min_idx = -1;

        // Find process with shortest BT among arrived and not yet done
        for (i = 0; i < n; i++) {
            if (!done[i] && at[i] <= current_time) {
                if (min_idx == -1 || bt[i] < bt[min_idx])
                    min_idx = i;
            }
        }

        // If no process has arrived yet, advance time
        if (min_idx == -1) {
            current_time++;
            count--;
            continue;
        }

        gantt_p[gantt_count]     = p[min_idx];
        gantt_start[gantt_count] = current_time;

        current_time += bt[min_idx];
        ct[min_idx]   = current_time;

        gantt_end[gantt_count] = current_time;
        gantt_count++;

        tat[min_idx] = ct[min_idx] - at[min_idx];
        wt[min_idx]  = tat[min_idx] - bt[min_idx];
        avg_wt       += wt[min_idx];
        avg_tat      += tat[min_idx];
        done[min_idx] = 1;
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);

    // Gantt Chart
    printf("\nGantt Chart:\n|");
    for (i = 0; i < gantt_count; i++)
        printf(" P%d |", gantt_p[i]);

    printf("\n%d", gantt_start[0]);
    for (i = 0; i < gantt_count; i++)
        printf("   %d", gantt_end[i]);

    printf("\n\nAvg WT  = %.2f", avg_wt / n);
    printf("\nAvg TAT = %.2f\n", avg_tat / n);

    return 0;
}
