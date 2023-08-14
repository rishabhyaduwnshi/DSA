#include <bits/stdc++.h>
using namespace std;

int countWays(int coins[], int current_index, int size, int sum, vector<vector<int>> &dp)
{
    if(sum == 0)
        return 1;
        
    if(sum < 0)
        return 0;
        
    if(current_index < 0)
        return 0;
    
    if(dp[current_index][sum] == -1)
    {
        int not_take = countWays(coins,current_index-1,size,sum,dp);
        int take =  countWays(coins,current_index,size,sum-coins[current_index],dp);
        return dp[current_index][sum] = take+not_take;
    }
    else
        return dp[current_index][sum];
}


int main()
{
    int coins[] = {2, 5, 3, 6};
    int n = sizeof(coins) / sizeof(int);
    int sum = 10;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    cout<<countWays(coins, n-1, n, sum,dp);
    return 0;
    
}
