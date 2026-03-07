/*QUESTION:
Given two sorted arrays nums1 and nums2 of sizes m and n respectively, you need to find the median of the two sorted arrays.

APPROACH:
To find the median of two sorted arrays, we can apply the concept of binary search. The overall time complexity of the solution should be O(log (m+n)).

1. First, we ensure that nums1 is the smaller sized array. If not, we swap nums1 and nums2.
2. Calculate the optimal count opt_cnt, which is (nums1.size() + nums2.size() + 1) / 2. This represents the median index in the merged array.
3. Initialize low to 0 and high to nums1.size() - 1.
4. Perform binary search until low is less than or equal to high:
     - Calculate the cut1 as low + (high - low) / 2, which represents the potential index to partition nums1.
     - Calculate cut2 as opt_cnt - cut1, which represents the corresponding index in nums2.
     - Calculate l1, l2, r1, and r2 as the left and right elements around the potential partition points.
     - If l1 is less than or equal to r2 and l2 is less than or equal to r1, it means we have found the correct partition points.
          - If the total number of elements is even, return the average of the maximum of l1 and l2 and the minimum of r1 and r2.
          - If the total number of elements is odd, return the maximum of l1 and l2.
     - If l1 is greater than r2, move the high pointer to cut1 - 1.
     - Otherwise, move the low pointer to cut1 + 1.
5. If no median is found, return 0.0.

CODE:*/
#include <stdio.h>
#include <limits.h>

double findMedian_Merge(int A[], int n, int B[], int m)
{
    int i = 0, j = 0, k = 0;
    int merged[n + m];

    // Merge arrays
    while(i < n && j < m)
    {
        if(A[i] < B[j])
            merged[k++] = A[i++];
        else
            merged[k++] = B[j++];
    }

    while(i < n)
        merged[k++] = A[i++];

    while(j < m)
        merged[k++] = B[j++];

    int total = n + m;

    if(total % 2 == 0)
        return (merged[total/2 - 1] + merged[total/2]) / 2.0;
    else
        return merged[total/2];
}

double findMedian_Binary(int A[], int n, int B[], int m)
{
    // Ensure A is smaller array
    if(n > m)
        return findMedian_Binary(B, m, A, n);

    int low = 0, high = n;

    while(low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = (n + m + 1)/2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : A[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : B[cut2-1];

        int r1 = (cut1 == n) ? INT_MAX : A[cut1];
        int r2 = (cut2 == m) ? INT_MAX : B[cut2];

        if(l1 <= r2 && l2 <= r1)
        {
            if((n+m)%2 == 0)
                return ( (l1>l2?l1:l2) + (r1<r2?r1:r2) ) / 2.0;
            else
                return (l1>l2?l1:l2);
        }
        else if(l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }

    return 0.0;
}

int main()
{
    int A[] = {1,2,3,4,8,10,11,12};
    int B[] = {8,10,11,12,19};  // 1,2,3,4,8,8,10,10,11,11,12,12,19
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    printf("Median = %.2lf\n", findMedian_Merge(A, n, B, m));
    printf("Median = %.2lf", findMedian_Binary(A,n,B,m));
}
/*
COMPLEXITY ANALYSIS:
- Time complexity: O(log(min(m, n))), where m and n are the sizes of the input arrays nums1 and nums2, respectively. We perform binary search on the smaller array.
- Space complexity: O(1), as we use constant extra space throughout the algorithm.
*/
