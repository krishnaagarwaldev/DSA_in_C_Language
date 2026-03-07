#include <stdio.h>

//arr = [1,2,3,4,5]
//reverse = [5,4,3,2,1]
void reverse(int arr[], int start, int end)
{
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

/*✅ Right Rotation (Important)

Right rotate by k:

Instead of:

reverse(0, k-1)
reverse(k, n-1)
reverse(0, n-1)

Do:

reverse(0, n-1)
reverse(0, k-1)
reverse(k, n-1)*/

// arr = [1,2,3,4,5], k = 2
// left rotate by k, arr = [3,4,5,1,2]
// right rotate by k, arr = [4,5,1,2,3]

void leftRotate(int arr[], int n, int k)
{
    k = k % n;   // handle k > n

    reverse(arr, 0, k - 1); // eg. k = 2, reverse(0, 1) => arr = [2,1,3,4,5]
    reverse(arr, k, n - 1); // eg. k = 2, reverse(2, 4) => arr = [2,1,5,4,3]
    reverse(arr, 0, n - 1); // eg. k = 2, reverse(0, 4) => arr = [3,4,5,1,2]
}

void rightRotate(int arr[], int n, int k)
{
    k = k % n;   // handle k > n

    reverse(arr, 0, n - 1); // eg. k = 2, reverse(0, 4) => arr = [5,4,3,2,1]
    reverse(arr, 0, k - 1); // eg. k = 2, reverse(0, 1) => arr = [4,5,3,2,1]
    reverse(arr, k, n - 1); // eg. k = 2, reverse(2, 4) => arr = [4,5,1,2,3]
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int k = 2;

    leftRotate(arr, n, k); // Rotate left by k eg. k = 2, arr = [3,4,5,1,2]
    printArray(arr, n);
    printf("\n");

    int arr2[] = {1,2,3,4,5};
    rightRotate(arr2, n, k); // Rotate right by k eg. k = 2, arr = [4,5,1,2,3]
    printArray(arr2, n);

    return 0;
}