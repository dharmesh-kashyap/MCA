#include <stdio.h>

int main() {
    int frames, pages, i, j, k, pageFaults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    
    int frame[frames], pageList[pages];
    int frameUsage[frames];  
    
    printf("Enter the reference string:\n");
    for(i = 0; i < pages; i++) {
        scanf("%d", &pageList[i]);
    }
    
    for(i = 0; i < frames; i++) {
        frame[i] = -1;  
        frameUsage[i] = 0;  
    }
    
    printf("\nReference String\tPage Frames\tPage Faults\n");
    for(i = 0; i < pages; i++) {
        printf("%d\t\t\t", pageList[i]);
        
        int found = 0;
        for(k = 0; k < frames; k++) {
            if(frame[k] == pageList[i]) {
                found = 1;
                frameUsage[k] = i + 1;  
                break;
            }
        }
        
        if(!found) {
            int leastUsed = 0;
            for(k = 1; k < frames; k++) {
                if(frameUsage[k] < frameUsage[leastUsed]) {
                    leastUsed = k;
                }
            }
            frame[leastUsed] = pageList[i];
            frameUsage[leastUsed] = i + 1;  
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
