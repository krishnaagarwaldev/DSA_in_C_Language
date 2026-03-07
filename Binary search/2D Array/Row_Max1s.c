/*
QUESTION:-
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input:
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).
*/

/*
APPROACH:-
-> We can use two pointer i and j which indicates current row and col
-> As we know the matrix is row-wise sorted we can intilaize j=m-1 i.e. last col and i=0 i.e. first row
-> Now, the idea is we will keep moving left j while we occur 1 and if 0 is found we will check in next row
-> The last row where we encountered 1 will be our ans

                {*0, *1, *1, *1}                  { 0, 1<-, 1<-, 1<-} <- start and zero comes change row i.e. i++
                {*0,  0,  1,  1}                   { 0, 0, 1, 1} 
out of matrix  *{*1,  1,  1,  1} ---> ans -->      {1<-, 1, 1, 1}
                {0,  0,  0,  0}                   {0, 0, 0, 0}



*/

// CODE:-
#include <stdio.h>

int rowWithMax1s(int arr[][100], int n, int m){
    int i = 0;
    int j = m - 1;
    int ans = -1;

    while(i < n && j >= 0){
        if(arr[i][j] == 1){
            ans = i;   // update answer
            j--;       // move left
        }
        else{
            i++;       // move down
        }
    }
    return ans;
}

int main(){
    int arr[3][100] = {
        {0,1,1,1},
        {0,0,1,1},
        {1,1,1,1}
    };

    int n = 3, m = 4;
    int result = rowWithMax1s(arr, n, m);
    printf("Row with maximum 1s: %d\n", result);
    return 0;
}

// TIME COMPLEXITY = O(N+M)
// SPACE COMPLEXITY = O(0)