#include <bits/stdc++.h>
using namespace std;


int rodCuttingProblem(int profit[], int current_index, int size, vector<vector<int>> &dp)
{
    if(current_index == 0)
        return size*profit[0];
        
    int not_take = 0;
    int take = 0;
    int rod_length = current_index+1;
    
    if(dp[current_index][size] == -1)
    { 
        not_take = rodCuttingProblem(profit,current_index-1,size,dp);
        if(rod_length <= size)
            take = profit[current_index]+rodCuttingProblem(profit,current_index,size-rod_length,dp);
        return dp[current_index][size] = max(take,not_take);
    }
    else 
        return dp[current_index][size];
            
}
    
int cutRod(int price[], int n) 
{
    vector<vector<int>> dp(n+1 ,vector<int>(n+1 ,-1));
    return rodCuttingProblem(price,n-1,n,dp);
}


int main()
{
    int profit[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int size = sizeof(profit) / sizeof(int);
    cout<<cutRod(profit,size);
    return 0;
    
}
