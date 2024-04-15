#include <stdio.h>

int main() {
    int frames, pages, i, j, k, pageFaults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    
    int frame[frames], pageList[pages];
    int frameUsage[frames];  // to track the oldest used frame
    
    printf("Enter the reference string:\n");
    for(i = 0; i < pages; i++) {
        scanf("%d", &pageList[i]);
    }
    
    for(i = 0; i < frames; i++) {
        frame[i] = -1;  // Initialize all frames to -1 (empty)
        frameUsage[i] = 0;  // Initialize frame usage to 0
    }
    
    printf("\nReference String\tPage Frames\tPage Faults\n");
    for(i = 0; i < pages; i++) {
        printf("%d\t\t\t", pageList[i]);
        
        int found = 0;
        for(k = 0; k < frames; k++) {
            if(frame[k] == pageList[i]) {
                found = 1;
                break;
            }
        }
        
        if(!found) {
            int oldest = 0;
            for(k = 1; k < frames; k++) {
                if(frameUsage[k] < frameUsage[oldest]) {
                    oldest = k;
                }
            }
            frame[oldest] = pageList[i];
            frameUsage[oldest] = i + 1;  // Update frame usage to current iteration
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
