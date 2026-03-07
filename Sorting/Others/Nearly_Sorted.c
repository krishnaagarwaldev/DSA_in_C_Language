#include <stdio.h>

void nearlySorted(int arr[], int n, int k)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Only check upto k positions back
        while(j >= 0 && j >= i - k && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {2, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    nearlySorted(arr, n, k);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}