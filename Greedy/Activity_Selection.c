#include <stdio.h>

int main() {
    int n = 6;
    int start[]  = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    // Sort by finish time (bubble sort)
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(finish[j] > finish[j+1]) {
                int t;

                t = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = t;

                t = start[j];
                start[j] = start[j+1];
                start[j+1] = t;
            }
        }
    }

    printf("Selected Activities:\n");

    int i = 0;
    printf("(%d, %d)\n", start[i], finish[i]);

    for(int j = 1; j < n; j++) {
        if(start[j] >= finish[i]) {
            printf("(%d, %d)\n", start[j], finish[j]);
            i = j;
        }
    }

    return 0;
}

//Dry run
// start = [1, 3, 0, 5, 8, 5]
// finish = [2, 4, 6, 7, 9, 9]
// After sorting by finish time:
// start = [1, 3, 0, 5, 5, 8]
// finish = [2, 4, 6, 7, 9, 9]
// Selected activities: (1, 2) (3, 4) (5, 7) (8, 9)
//Dry run explanation:
//1. We start by selecting the first activity (1, 2) since it finishes earliest.
//2. Next, we look for the next activity that starts after 2. We find (3, 4) and select it.
//3. Then, we look for the next activity that starts after 4. We find (5, 7) and select it.
//4. Finally, we look for the next activity that starts after 7. We find (8, 9) and select it.  
