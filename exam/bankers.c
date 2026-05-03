#include <stdio.h>

int n, m;
int alloc[10][10], max[10][10], need[10][10], avail[10];

void calcNeed() {
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

int validate() {
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(need[i][j] < 0) {
                printf("Error: P%d has Alloc > Max for resource %d. Invalid input.\n", i+1, j+1);
                return 0;
            }
    return 1;
}

void checkSafe() {
    int finish[10]={0}, seq[10], work[10], count=0, found;
    for(int i=0; i<m; i++) work[i]=avail[i];

    while(count<n) {
        found=0;
        for(int i=0; i<n; i++) {
            if(finish[i]) continue;
            int ok=1;
            for(int j=0; j<m; j++)
                if(need[i][j]>work[j]) { ok=0; break; }
            if(ok) {
                for(int j=0; j<m; j++) work[j]+=alloc[i][j];
                seq[count++]=i; finish[i]=1; found=1;
            }
        }
        if(!found) { printf("System is in UNSAFE state!\n"); return; }
    }

    printf("System is in SAFE state.\nSafe sequence: ");
    for(int i=0; i<n; i++) printf("P%d ", seq[i]+1);
    printf("\n");
}

int main() {
    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);

    printf("Enter Allocation Matrix:\n");
    for(int i=0; i<n; i++) {
        printf("  P%d: ", i+1);
        for(int j=0; j<m; j++) scanf("%d", &alloc[i][j]);
    }

    printf("Enter Max Matrix:\n");
    for(int i=0; i<n; i++) {
        printf("  P%d: ", i+1);
        for(int j=0; j<m; j++) scanf("%d", &max[i][j]);
    }

    printf("Enter Available Resources: ");
    for(int i=0; i<m; i++) scanf("%d", &avail[i]);

    calcNeed();

    printf("\nCalculated Need Matrix:\n");
    printf("Process | Resources\n");
    printf("-------------------\n");
    for(int i=0; i<n; i++) {
        printf("  P%-2d   | ", i+1);
        for(int j=0; j<m; j++) printf("%d ", need[i][j]);
        printf("\n");
    }

    if(!validate()) return 1;

    checkSafe();
}