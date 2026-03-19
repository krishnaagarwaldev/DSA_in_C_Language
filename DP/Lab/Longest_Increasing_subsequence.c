// Problem 3 -> Longest Increasing Subsequence

#include <stdio.h>
#define Max 100

int main(){
    int array[Max], length[Max], link[Max];
    int total;

    printf("Enter number of elements: ");
    scanf("%d", &total);

    printf("Enter elements:\n");
    for (int x = 0; x < total; x++){
        scanf("%d", &array[x]);
    }
    for (int x = 0; x < total; x++){
        length[x] = 1;
        link[x] = -1;
    }
    for (int x = 1; x < total; x++){
        for (int y = 0; y < x; y++){
            if (array[x] > array[y] && length[y] + 1 > length[x]){
                length[x] = length[y] + 1;
                link[x] = y;
            }
        }
    }

    int best = length[0], idx = 0;
    for (int x = 1; x < total; x++){
        if (length[x] > best){
            best = length[x];
            idx = x;
        }
    }
    printf("\nLength: %d\n", best);

    int LIS[Max], count = 0;

    while (idx != -1){
        LIS[count++] = array[idx];
        idx = link[idx];
    }
    printf("Sequence: ");
    for (int x = count - 1; x >= 0; x--){
        printf("%d ", LIS[x]);
    }

    return 0;
}
