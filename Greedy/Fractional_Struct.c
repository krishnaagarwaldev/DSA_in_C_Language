// qsort(base_address, number_of_elements, size_of_each_element, comparator_function);
// Comparator function should return a negative value if the first argument is less than the second, zero if they are equal, and a positive value if the first argument is greater than the second.
/*
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);   // ascending
}
*/ 
/*
✅ Approach

Create struct with profit, weight, ratio
Calculate ratio
Sort in descending order of ratio
Take full items until capacity
Take fraction of last item
*/

#include <stdio.h>
#include <stdlib.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

// Comparator for descending ratio
int compare(const void *a, const void *b) {
    struct Item *i1 = (struct Item *)a;
    struct Item *i2 = (struct Item *)b;

    if (i2->ratio > i1->ratio)
        return 1;
    else if (i2->ratio < i1->ratio)
        return -1;
    else
        return 0;
}

int main() {
    int n = 3;
    int capacity = 50;

    struct Item items[] = {
        {60, 10, 0},
        {100, 20, 0},
        {120, 30, 0}
    };

    // Step 1: Calculate ratio
    for(int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    // Step 2: Sort by ratio descending
    qsort(items, n, sizeof(struct Item), compare);

    float totalProfit = 0;

    // Step 3: Greedy selection
    for(int i = 0; i < n; i++) {
        if(capacity >= items[i].weight) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}