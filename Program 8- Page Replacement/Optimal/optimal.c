#include <stdio.h>

int predict(int pages[], int mem[], int n, int index, int frames) {
    int farthest = index, pos = -1;
    for (int i = 0; i < frames; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (mem[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n) return i; // Not used again
    }
    return (pos == -1) ? 0 : pos;
}

int main() {
    int n, frames;
    int pages[100], mem[10], faults = 0, count = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (mem[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (count < frames) {
                mem[count++] = pages[i];
            } else {
                int replace = predict(pages, mem, n, i + 1, frames);
                mem[replace] = pages[i];
            }
            faults++;
        }
    }

    printf("Total Page Faults: %d\n", faults);
    return 0;
}
