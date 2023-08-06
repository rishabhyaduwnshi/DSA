#include<bits/stdc++.h>
using namespace std;

bool dp[1000][1000];

bool isSubsetSum(int subset_array[], int length, int sum)
{
    if(length == 0)
        return false;
    
    if(sum == 0)
        return true;
        
    if(dp[length][sum] == true)
        return true;
        
        
    if (sum >= subset_array[length - 1])
        dp[length][sum] = dp[length][sum] || isSubsetSum(subset_array, length - 1, sum - subset_array[length - 1]);
        
    return dp[length][sum];
}





int main()
{
    memset(dp,false,sizeof(dp));
    int subset_array[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 30;
    int n = sizeof(subset_array) / sizeof(subset_array[0]);
    if (isSubsetSum(subset_array, n, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}
