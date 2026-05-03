#include <stdio.h>

int main() {
    int pages[50], memory[10];
    int n, frames, i, j, k = 0, found, page_faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
        memory[i] = -1;

    printf("\nFIFO Page Replacement:\n");

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < frames; j++) {
            if(memory[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            memory[k] = pages[i];
            k = (k + 1) % frames;
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
