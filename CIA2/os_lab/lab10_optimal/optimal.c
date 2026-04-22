#include <stdio.h>

int main() {
    int pages[50], memory[10];
    int n, frames, i, j, k, pos, farthest, page_faults = 0;
    int found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
        memory[i] = -1;

    printf("\nOptimal Page Replacement:\n");

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < frames; j++) {
            if(memory[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            int empty = -1;

            for(j = 0; j < frames; j++) {
                if(memory[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                memory[empty] = pages[i];
            } else {
                farthest = -1;

                for(j = 0; j < frames; j++) {
                    int next_use = -1;

                    for(k = i + 1; k < n; k++) {
                        if(memory[j] == pages[k]) {
                            next_use = k;
                            break;
                        }
                    }

                    if(next_use == -1) {
                        pos = j;
                        break;
                    }

                    if(next_use > farthest) {
                        farthest = next_use;
                        pos = j;
                    }
                }

                memory[pos] = pages[i];
            }

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
