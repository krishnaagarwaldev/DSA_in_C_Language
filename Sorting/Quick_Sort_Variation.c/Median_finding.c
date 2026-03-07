#include <stdio.h>

/* ---------------- SWAP FUNCTION ---------------- */
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ---------------- SORT SMALL ARRAY (SIZE <=5) ---------------- */
int findMedian(int arr[], int n){
    // Simple insertion sort
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr[n / 2];   // Return middle element
}

/* ---------------- PARTITION FUNCTION ---------------- */
int partition(int arr[], int low, int high, int pivotValue){
    // Find pivot index
    int pivotIndex;
    for (pivotIndex = low; pivotIndex <= high; pivotIndex++)
        if (arr[pivotIndex] == pivotValue)
            break;

    // Move pivot to end
    swap(&arr[pivotIndex], &arr[high]);
    int storeIndex = low;

    // Move elements smaller than pivot to left
    for (int i = low; i < high; i++){
        if (arr[i] < pivotValue)
        {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }

    // Place pivot in correct position
    swap(&arr[storeIndex], &arr[high]);

    return storeIndex;
}

/* ---------------- DETERMINISTIC SELECT ---------------- */
int deterministicSelect(int arr[], int low, int high, int k){
    if (low == high)
        return arr[low];

    int n = high - low + 1;

    // Number of groups of 5
    int numGroups = (n + 4) / 5;
    int medians[numGroups];

    int i;
    for (i = 0; i < numGroups; i++){
        int groupStart = low + i * 5;
        int groupSize = 5;

        if (groupStart + 5 > high + 1)
            groupSize = high - groupStart + 1;

        medians[i] = findMedian(&arr[groupStart], groupSize);
    }

    // Find median of medians
    int medOfMed;
    if (numGroups == 1)
        medOfMed = medians[0];
    else
        medOfMed = deterministicSelect(medians, 0, numGroups - 1, numGroups / 2);

    // Partition around median of medians
    int pivotIndex = partition(arr, low, high, medOfMed);

    if (k == pivotIndex)
        return arr[k];
    else if (k < pivotIndex)
        return deterministicSelect(arr, low, pivotIndex - 1, k);
    else
        return deterministicSelect(arr, pivotIndex + 1, high, k);
}

/* ---------------- MAIN ---------------- */
int main(){
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = n / 2;   // 0-based index

    if (n % 2 == 1){
        int median = deterministicSelect(arr, 0, n - 1, k);
        printf("Median: %d\n", median);
    }
    else{
        int m1 = deterministicSelect(arr, 0, n - 1, k - 1);
        int m2 = deterministicSelect(arr, 0, n - 1, k);
        printf("Median: %.2f\n", (m1 + m2) / 2.0);
    }

    return 0;
}