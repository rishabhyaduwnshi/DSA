#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int weight[], int profit[],int size, int capacity, vector<vector<int>> &dp)
{
    if(size == 0)
        return 0;
        
    if(dp[size][capacity] == -1)
    { 
        if(weight[size-1] > capacity)
            return dp[size][capacity] = unboundedKnapsack(weight,profit,size-1,capacity,dp);
        else
            return dp[size][capacity] = max(profit[size-1]+unboundedKnapsack(weight,profit,size,capacity-weight[size-1],dp), 
                                    unboundedKnapsack(weight,profit,size-1,capacity,dp));
    }
    else
        return dp[size][capacity];
    
    
}




int main()
{
    int capacity = 100;
    int profit[] = { 10, 30, 20 };
    int weight[] = { 5, 10, 15 };
    int size = sizeof(profit) / sizeof(int);
 
    vector<vector<int>>dp(size+1, vector<int>(capacity+1,-1));
    
    cout << unboundedKnapsack(weight, profit, size,capacity,dp);
    return 0;
    
}
