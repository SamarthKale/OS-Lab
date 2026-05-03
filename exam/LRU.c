#include <stdio.h>

int main()
{
    int pages[50], f[10], last[10];
    int n, size, faults = 0, hits = 0, time = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &size);

    // Initialize
    for (int i = 0; i < size; i++)
    {
        f[i] = -1;
        last[i] = -1;
    }

    printf("\nProcess:\n");

    for (int i = 0; i < n; i++)
    {
        int hit = 0;

        // Check for hit
        for (int j = 0; j < size; j++)
        {
            if (f[j] == pages[i])
            {
                hit = 1;
                last[j] = time++;
                hits++;
                break;
            }
        }

        // If fault → replace LRU
        if (hit == 0)
        {
            int lru = 0;

            for (int j = 1; j < size; j++)
            {
                if (last[j] < last[lru])
                {
                    lru = j;
                }
            }

            f[lru] = pages[i];
            last[lru] = time++;
            faults++;
        }

        // Print frames
        for (int j = 0; j < size; j++)
        {
            if (f[j] == -1)
            {
                printf("- ");
            }
            else
            {
                printf("%d ", f[j]);
            }
        }

        // Print Hit/Fault
        if (hit)
        {
            printf("(Hit)\n");
        }
        else
        {
            printf("(Fault)\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Hits: %d\n", hits);

    return 0;
}