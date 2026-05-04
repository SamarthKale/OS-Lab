#include <stdio.h>

int main()
{
    int pages[50], f[10];
    int n, size, faults = 0, hits = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &size);

    // Initialize frames
    for (int i = 0; i < size; i++)
        f[i] = -1;

    printf("\nProcess:\n");

    for (int i = 0; i < n; i++)
    {
        int hit = 0;

        // Check hit
        for (int j = 0; j < size; j++)
        {
            if (f[j] == pages[i])
            {
                hit = 1;
                hits++;
                break;
            }
        }

        // If fault → replace optimal
        if (hit == 0)
        {
            int pos = -1, farthest = i + 1;

            for (int j = 0; j < size; j++)
            {
                int k;

                // Find next use
                for (k = i + 1; k < n; k++)
                {
                    if (f[j] == pages[k])
                        break;
                }

                // If never used again
                if (k == n)
                {
                    pos = j;
                    break;
                }

                // Choose farthest use
                if (k > farthest)
                {
                    farthest = k;
                    pos = j;
                }
            }

            // If all used soon, replace first
            if (pos == -1)
                pos = 0;

            f[pos] = pages[i];
            faults++;
        }

        // Print frames
        for (int j = 0; j < size; j++)
        {
            if (f[j] == -1)
                printf("- ");
            else
                printf("%d ", f[j]);
        }

        // Print status
        if (hit)
            printf("(Hit)\n");
        else
            printf("(Fault)\n");
    }

    printf("\nTotal Faults: %d\n", faults);
    printf("Total Hits: %d\n", hits);

    return 0;
}