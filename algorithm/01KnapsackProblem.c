#include <stdio.h>

// will return the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// put in a knapsack of capacity W
//either the object can be added(1) or discarded(0).
int knapSack(int W, int wt[], int val[], int n)
{
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more than Knapsack capacity W, then this item cannot be included in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1],
                           wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
 
int main()
{
    int val[] = { 60,45,22,67,500, 120 };
    int wt[] = { 10,32,15,20,30,40 };
    int W = 70;
    int n = sizeof(val) / sizeof(val[0]);
    printf("Max weight possible is %d", knapSack(W, wt, val, n));
    return 0;
}
