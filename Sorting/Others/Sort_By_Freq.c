#include <stdio.h>

int main()
{
    int arr[] = {5, 5, 4, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int freq[n];

    // Step 1: Count frequency of each element
    for(int i = 0; i < n; i++)
    {
        freq[i] = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[i] == arr[j])
                freq[i]++;
        }
    }

    // Step 2: Sort based on frequency
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            // If freq smaller → swap
            // If freq equal and arr[j] bigger → swap
            if(freq[j] < freq[j+1] || 
              (freq[j] == freq[j+1] && arr[j] > arr[j+1]))
            {
                // swap frequency
                int tempf = freq[j];
                freq[j] = freq[j+1];
                freq[j+1] = tempf;

                // swap array
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Step 3: Print result
    printf("Sorted by frequency:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}