#include <stdio.h>
#include <stdbool.h>

int main() {
    int frames, pages, i, j, k, pageFaults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    
    int frame[frames], pageList[pages], nextUse[frames];
    
    printf("Enter the reference string:\n");
    for(i = 0; i < pages; i++) {
        scanf("%d", &pageList[i]);
    }
    
    for(i = 0; i < frames; i++) {
        frame[i] = -1;  // Initialize all frames to -1 (empty)
        nextUse[i] = 0;  // Initialize next use to 0
    }
    
    printf("\nReference String\tPage Frames\tPage Faults\n");
    for(i = 0; i < pages; i++) {
        printf("%d\t\t\t", pageList[i]);
        
        bool found = false;
        for(k = 0; k < frames; k++) {
            if(frame[k] == pageList[i]) {
                found = true;
                break;
            }
        }
        
        if(!found) {
            int index = -1, farthest = 0;
            for(k = 0; k < frames; k++) {
                int l;
                for(l = i + 1; l < pages; l++) {
                    if(frame[k] == pageList[l]) {
                        if(l > farthest) {
                            farthest = l;
                            index = k;
                        }
                        break;
                    }
                }
                if(l == pages) {
                    index = k;
                    break;
                }
            }
            frame[index] = pageList[i];
            pageFaults++;
        }
        
        for(k = 0; k < frames; k++) {
            if(frame[k] != -1) {
                printf("%d ", frame[k]);
            } else {
                printf("- ");
            }
        }
        printf("\t\t%d\n", pageFaults);
    }
    
    printf("\nTotal Page Faults: %d\n", pageFaults);
    
    return 0;
}
