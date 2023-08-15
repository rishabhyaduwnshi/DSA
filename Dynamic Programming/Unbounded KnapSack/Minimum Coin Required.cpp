int minCoins(vector<int> &coins, int current_index, int sum, vector<vector<int>> &dp)
{
    if(current_index < 0 )
    {
        if(sum == 0)
            return 0;
        else
            return -1;
    }
    
    if(sum < 0)
        return -1;

    if(dp[current_index][sum] == -2)
    {
        int take = 0;
        int not_take = 0;
        
        take = minCoins(coins,current_index,sum-coins[current_index],dp);
        not_take = minCoins(coins,current_index-1,sum,dp);

        if(take == -1)
            return not_take;
        
        if(not_take == -1)
            return take+1;

        if(take != -1 && not_take != -1)
            return dp[current_index][sum] = min(take+1,not_take);
    }
    
    else if (dp[current_index][sum] >= 0)
        return dp[current_index][sum];
    
    else
        return -1;

        return -1;
    }

int coinChange(vector<int>& coins, int amount) 
{
    vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-2));
    return minCoins(coins,coins.size()-1,amount,dp);
}
