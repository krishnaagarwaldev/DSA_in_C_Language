#include <stdio.h>

/* ---------- Swap ---------- */
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

/* ---------- Sort small array (size <= 5) ---------- */
int findMedian(int a[], int n){
    int i, j, key;

    // Insertion sort
    for(i = 1; i < n; i++){
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    return a[n/2];
}

/* ---------- Partition ---------- */
int partition(int a[], int low, int high, int pivot){
    int i, pos;

    // Find pivot position
    for(pos = low; pos <= high; pos++)
        if(a[pos] == pivot)
            break;

    // Move pivot to end
    swap(&a[pos], &a[high]);

    i = low;

    for(int j = low; j < high; j++){
        if(a[j] < pivot){
            swap(&a[i], &a[j]);
            i++;
        }
    }

    swap(&a[i], &a[high]);
    return i;
}

/* ---------- Deterministic Select ---------- */
int select(int a[], int low, int high, int k){
    if(low == high)
        return a[low];

    int n = high - low + 1;

    int m[(n+4)/5];   // medians array
    int i;

    // Divide into groups of 5
    for(i = 0; i < (n+4)/5; i++){
        int start = low + i*5;
        int size = 5;

        if(start + 5 > high+1)
            size = high - start + 1;

        m[i] = findMedian(&a[start], size);
    }

    // Find median of medians
    int med;
    if(i == 1)
        med = m[0];
    else
        med = select(m, 0, i-1, i/2);

    int pos = partition(a, low, high, med);

    if(k == pos)
        return a[pos];
    else if(k < pos)
        return select(a, low, pos-1, k);
    else
        return select(a, pos+1, high, k);
}

/* ---------- Main ---------- */
int main(){
    int a[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(a)/sizeof(a[0]);
    int k = n/2;   // 0-based index

    if(n % 2 == 1){
        printf("Median: %d\n", select(a, 0, n-1, k));
    }
    else{
        int x = select(a, 0, n-1, k-1);
        int y = select(a, 0, n-1, k);
        printf("Median: %.2f\n", (x + y)/2.0);
    }
    return 0;
}