// LRU Page Replacement
#include <stdio.h>

int main() {
    int pages[50], f[10], last[10];
    int n, size, faults=0, hits=0, timer=1;

    // ---------- INPUT ----------
    printf("Enter reference string length: ");
    scanf("%d", &n);
    printf("Enter reference string:\n");
    for(int i=0; i<n; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &size);

    // Initialize frames and last used time to -1/0
    for(int i=0; i<size; i++) { f[i]=-1; last[i]=0; }

    // ---------- LRU LOGIC ----------
    printf("\nProcess:\n");
    for(int i=0; i<n; i++) {
        int hit=0;

        // Check if page already in frame — Hit
        for(int j=0; j<size; j++) {
            if(f[j]==pages[i]) {
                hit=1;
                last[j]=timer++;  // update last used time
                hits++;
                break;
            }
        }

        if(!hit) {
            // Find least recently used frame (smallest last used time)
            int lru=0;
            for(int j=1; j<size; j++)
                if(last[j]<last[lru]) lru=j;

            // Replace LRU frame with new page
            f[lru]=pages[i];
            last[lru]=timer++;
            faults++;
        }

        // Print current frame state
        for(int j=0; j<size; j++) f[j]==-1 ? printf("- ") : printf("%d ", f[j]);
        printf(hit ? "(Hit)\n" : "(Fault)\n");
    }

    // ---------- RESULTS ----------
    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Hits: %d\n", hits);
    printf("Hit Ratio: %.2f\n", (float)hits/n);
}