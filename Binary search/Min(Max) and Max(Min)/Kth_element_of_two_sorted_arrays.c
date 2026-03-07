/*
Question:-
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K.
Find the element that would be at the kth position of the final sorted array.

Example:- 

Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.

Approach:
1. Compare the sizes of the two arrays, arr1 and arr2. If the size of arr1 is greater than arr2, swap the arrays to ensure arr1 is the smaller sized array.
2. Set the low and high variables for binary search.
   - If m < k, set low = k - m, otherwise set low = 0.
   - If k < n, set high = k, otherwise set high = n.
3. Perform binary search within the range [low, high] to find the kth element.
4. In each iteration of binary search:
   - Calculate the cut positions, cut1 and cut2, based on the mid position.
   - Determine the left and right elements of arr1 and arr2 based on the cut positions.
   - Compare the left and right elements and adjust the low and high pointers accordingly.
5. Return the maximum element among the left elements, as it would be the kth element in the final sorted array.

CODE
*/

#include <stdio.h>
#include <limits.h>

int kthElement_Naive(int A[], int n, int B[], int m, int k){
    int i = 0, j = 0, count = 0;

    while(i < n && j < m){
        if(A[i] < B[j]){
            count++;
            if(count == k) return A[i];
            i++;
        }
        else{
            count++;
            if(count == k) return B[j];
            j++;
        }
    }
    while(i < n){
        count++;
        if(count == k) return A[i];
        i++;
    }
    while(j < m){
        count++;
        if(count == k) return B[j];
        j++;
    }
    return -1;
}

int kthElement_Binary(int A[], int n, int B[], int m, int k){
    if(n > m)
        return kthElement_Binary(B, m, A, n, k);

    int low = (k > m) ? k - m : 0;
    int high = (k < n) ? k : n;

    while(low <= high){
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : A[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : B[cut2-1];

        int r1 = (cut1 == n) ? INT_MAX : A[cut1];
        int r2 = (cut2 == m) ? INT_MAX : B[cut2];

        if(l1 <= r2 && l2 <= r1)
            return (l1 > l2 ? l1 : l2);
        else if(l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return -1;
}

int main()
{
    int A[] = {2,3,6,7,9};
    int B[] = {1,4,8,10};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);
    int k = 5;
    printf("Kth Element = %d", kthElement_Binary(A,n,B,m,k));
    printf("\nKth Element = %d", kthElement_Naive(A,n,B,m,k));
    return 0;
}
/*
Time Complexity: O(log(min(N, M)))
Space Complexity: O(1)
*/
