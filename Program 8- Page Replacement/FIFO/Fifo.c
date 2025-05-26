#include <stdio.h>

int main() {
    int i, j, n, frames, faults = 0, index = 0;
    int ref[50], mem[10];

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
        mem[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < frames; j++) {
            if(mem[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            mem[index] = ref[i];
            index = (index + 1) % frames;
            faults++;
        }
    }

    printf("Total Page Faults: %d\n", faults);
    return 0;
}
