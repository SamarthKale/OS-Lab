#include <stdio.h>
#include <limits.h>
int main() {
 int n, i, time = 0, smallest, count = 0;
 int bt[20], rt[20], at[20];
 int wt[20], tat[20];
 int finish_time;
 float total_wt = 0, total_tat = 0;
 printf("Enter number of processes: ");
 scanf("%d", &n);
 for(i = 0; i < n; i++) {
 printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
 scanf("%d %d", &at[i], &bt[i]);
 rt[i] = bt[i]; // remaining time
 }
 rt[19] = INT_MAX;
 while(count != n) {
 smallest = 19;
 for(i = 0; i < n; i++) {
 if(at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0)
 smallest = i;
 }
 rt[smallest]--;
 time++;
 if(rt[smallest] == 0) {
 count++;
 finish_time = time;
 wt[smallest] = finish_time - at[smallest] - bt[smallest];
 if(wt[smallest] < 0)
 wt[smallest] = 0;
 tat[smallest] = bt[smallest] + wt[smallest];
 total_wt += wt[smallest];
 total_tat += tat[smallest];
 }
 }
printf("\nProcess\tAT\tBT\tWT\tTAT\n");
 for(i = 0; i < n; i++) {
 printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
 }
 printf("\nAverage Waiting Time = %.2f", total_wt/n);
 printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);
 return 0;
}
