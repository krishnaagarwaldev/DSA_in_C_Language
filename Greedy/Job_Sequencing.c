/*
Question:
Given a set of N jobs where each job 'i' has a deadline and profit associated with it. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline. Find the number of jobs done and the maximum profit.

Example:
Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with a maximum profit of 60 (20+40).

Complexity Analysis:
- The time complexity of this approach is O(NlogN), where N is the number of jobs.
- This is due to the sorting operation on the 'jobs' vector based on profits.
- The space complexity is O(N) as we use additional vectors to store the jobs and deadlines.

Code:
*/

#include <stdio.h>

int main() {
    int n = 4;

    char job[] = {'A','B','C','D'};
    int deadline[] = {2,1,2,1};
    int profit[] = {100,19,27,25};

    // Sort by profit descending
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(profit[j] < profit[j+1]) {
                int t;
                char c;

                t = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = t;

                t = deadline[j];
                deadline[j] = deadline[j+1];
                deadline[j+1] = t;

                c = job[j];
                job[j] = job[j+1];
                job[j+1] = c;
            }
        }
    }

    int slot[10] = {0};   // to check free slots
    char result[10];

    int totalProfit = 0;

    for(int i = 0; i < n; i++) {
        for(int j = deadline[i]-1; j >= 0; j--) {
            if(slot[j] == 0) {
                slot[j] = 1;
                result[j] = job[i];
                totalProfit += profit[i];
                break;
            }
        }
    }

    printf("Selected Jobs: ");
    for(int i = 0; i < n; i++) {
        if(slot[i])
            printf("%c ", result[i]);
    }

    printf("\nTotal Profit = %d\n", totalProfit);

    return 0;
}