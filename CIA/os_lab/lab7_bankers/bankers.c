#include <stdio.h>

int main() {
    int n, m, i, j, k = 0;

    printf("Processes & Resources: ");
    scanf("%d %d", &n, &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m], finish[n], seq[n];

    printf("Allocation:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Max:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Available:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for(i = 0; i < n; i++) {
        finish[i] = 0;
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    for(int count = 0; count < n; count++) {
        for(i = 0; i < n; i++) {
            if(!finish[i]) {
                int ok = 1;
                for(j = 0; j < m; j++)
                    if(need[i][j] > avail[j])
                        ok = 0;

                if(ok) {
                    for(j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    seq[k++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    if(k == n) {
        printf("Safe sequence: ");
        for(i = 0; i < n; i++)
            printf("P%d ", seq[i]);
    } else {
        printf("Not safe");
    }

    return 0;
}
