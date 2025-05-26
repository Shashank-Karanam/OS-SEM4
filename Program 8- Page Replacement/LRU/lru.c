#include <stdio.h>

int search(int arr[], int n, int key) {
    for(int i = 0; i < n; i++)
        if(arr[i] == key)
            return i;
    return -1;
}

int main() {
    int ref[50], mem[10], n, frames, faults = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int count = 0;
    for(int i = 0; i < n; i++) {
        int pos = search(mem, count, ref[i]);

        if(pos == -1) {
            if(count < frames)
                mem[count++] = ref[i];
            else {
                int lru = i, index;
                for(int j = 0; j < frames; j++) {
                    int k;
                    for(k = i - 1; k >= 0; k--) {
                        if(ref[k] == mem[j]) break;
                    }
                    if(k < lru) {
                        lru = k;
                        index = j;
                    }
                }
                mem[index] = ref[i];
            }
            faults++;
        }
    }

    printf("Total Page Faults: %d\n", faults);
    return 0;
}
