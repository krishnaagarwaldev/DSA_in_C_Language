// qsort(base_address, number_of_elements, size_of_each_element, comparator_function);

// Comparator function should return a negative value if the first argument is less than the second, zero if they are equal, and a positive value if the first argument is greater than the second.
/*
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);   // ascending
}
*/ 
/*
✅ Approach
Struct with id, deadline, profit
Sort jobs by profit (descending)
Create slot array
Assign job to latest possible free slot before deadline
*/

#include <stdio.h>
#include <stdlib.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

// Sort by profit descending
int compare(const void *a, const void *b) {
    struct Job *j1 = (struct Job *)a;
    struct Job *j2 = (struct Job *)b;

    return j2->profit - j1->profit;
}

int main() {
    int n = 4;

    struct Job jobs[] = {
        {'A',2,100},
        {'B',1,19},
        {'C',2,27},
        {'D',1,25}
    };

    // Step 1: Sort by profit
    qsort(jobs, n, sizeof(struct Job), compare);

    int slot[10] = {0};
    char result[10];
    int totalProfit = 0;

    // Step 2: Assign jobs
    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline - 1; j >= 0; j--) {
            if(slot[j] == 0) {
                slot[j] = 1;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Selected Jobs: ");
    for(int i = 0; i < n; i++) {
        if(slot[i])
            printf("%c ", result[i]);
    }

    printf("\nTotal Profit = %d\n", totalProfit);

    return 0;
}