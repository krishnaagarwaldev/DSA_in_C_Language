/*
QUESTION:
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

Example:

Input:
x = 5
Output: 2
Explanation: Since 5 is not a perfect square, the floor of the square root of 5 is 2.

Input:
x = 4
Output: 2
Explanation: Since 4 is a perfect square, the square root of 4 is 2.

APPROACH:
We can use binary search to find the square root of x. 
1. Initialize the search space with low = 1 and high = x.
2. While low is less than or equal to high:
     - Calculate the mid of the search space.
     - If the square of mid is equal to x, return mid as the square root.
     - If the square of mid is less than x, update the answer to mid and set low = mid + 1 to search for a larger value.
     - If the square of mid is greater than x, set high = mid - 1 to search for a smaller value.
3. Return the answer, which represents the floor of the square root of x.

CODE:
*/
#include <stdio.h>
#include <stdlib.h>

long long int floorSqrt1(long long int x) 
{
    long long int low = 1, high = x;
    long long int ans = -1;
    while(low <= high){
        long long int mid = low + (high - low) / 2;
        if(x == mid * mid)
            return mid;
        else if(mid * mid < x){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

/*
Time Complexity: O(log(x))
Space Complexity: O(1)
*/

// eg. x = 17
// therefore arr = [0,1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17]
// low = 0, high = 17, mid = 8, mid*mid = 64 > 17, therefore high = mid - 1 = 7
// low = 0, high = 7, mid = 3, mid*mid = 9 < 17, therefore ans = mid = 3, low = mid + 1 = 4
// low = 4, high = 7, mid = 5, mid*mid = 25 > 17, therefore high = mid - 1 = 4
// low = 4, high = 4, mid = 4, mid*mid = 16 < 17, therefore ans = mid = 4, low = mid + 1 = 5
// low = 5, high = 4, loop terminates, return ans = 4

int floorSqrt2(int x) {
    int low = 0, high = x, ans = 0;   

    while (low <= high) {
        int mid = (low + high) / 2;

        if ((long long)mid * mid <= x) {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main() {
    int x = 17;
    printf("The floor of the square root of %d is %d\n", x, floorSqrt1(x));
    printf("The floor of the square root of %d is %d\n", x, floorSqrt2(x));
    return 0;
}