#include<stdio.h>

#define MAX_FRAMES 10

int main() {
    int page_faults = 0, frames[MAX_FRAMES], pages[MAX_FRAMES];
    int n, i, j, k, flag = 0, pos = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference sequence: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    for(i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("\nPage\t   Frames\n");
    for(i = 0; i < n; i++) {
        printf("%d\t   ", pages[i]);
        flag = 0;
        for(j = 0; j < MAX_FRAMES; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            frames[pos] = pages[i];
            pos = (pos + 1) % MAX_FRAMES;
            page_faults++;
        }

        for(k = 0; k < MAX_FRAMES; k++) {
            printf("%d ", frames[k]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", page_faults);

    return 0;
}