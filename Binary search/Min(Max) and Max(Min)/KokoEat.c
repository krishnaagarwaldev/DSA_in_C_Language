/*
QUESTION:
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

EXAMPLES:
Input: piles = [3,6,7,11], h = 8
Output: 4

Input: piles = [30,11,23,4,20], h = 5
Output: 30

APPROACH:
- We can apply binary search to find the minimum eating speed.
- The eating speed can range from 1 to the maximum number of bananas in a pile.
- For each eating speed, we check if it is possible to finish eating all the bananas within h hours.
- We calculate the required time based on the eating speed, considering the number of bananas in each pile.
- If the required time is less than or equal to h, it means it is possible to finish eating all the bananas within h hours.
- We update the answer accordingly and continue the binary search.


CODE:
*/

#include <stdio.h>
int canEat(int arr[], int n, int H, int speed) {
    int hours = 0;

    for (int i = 0; i < n; i++) {
        hours += (arr[i] + speed - 1) / speed;  // ceil division
    }

    if (hours <= H)
        return 1;
    return 0;
}

int kokoEating(int arr[], int n, int H) {
    int low = 1;
    int high = arr[0];

    // find max pile
    for (int i = 0; i < n; i++)
        if (arr[i] > high)
            high = arr[i];

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canEat(arr, n, H, mid)) {
            result = mid;      // possible
            high = mid - 1;    // try smaller speed
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int piles[] = {3, 6, 7, 11};
    int h = 8;
    int n = sizeof(piles) / sizeof(piles[0]);

    int result = kokoEating(piles, n, h);
    printf("Minimum eating speed: %d\n", result);

    return 0;
}

// TIME COMPLEXITY: O(N log M), where N is the number of piles and M is the maximum number of bananas in a pile.
// SPACE COMPLEXITY: O(1)