#include <stdio.h>

int main() {
    int pages[50], memory[10], time[10];
    int n, frames, i, j, found, pos, min;
    int page_faults = 0, counter = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++) {
        memory[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement:\n");

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < frames; j++) {
            if(memory[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found) {
            min = time[0];
            pos = 0;

            for(j = 1; j < frames; j++) {
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            memory[pos] = pages[i];
            counter++;
            time[pos] = counter;
            page_faults++;
        }

        printf("\nPage %d -> ", pages[i]);

        for(j = 0; j < frames; j++) {
            if(memory[j] != -1)
                printf("%d ", memory[j]);
            else
                printf("- ");
        }

        if(found)
            printf(" (Hit)");
        else
            printf(" (PF)");
    }

    printf("\n\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
