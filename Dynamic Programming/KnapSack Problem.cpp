#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];


int knapsackProblem(int weight[], int profit[], int length, int capacity)
{
    if(length == 0 || capacity == 0)
        return 0;
    
    if(dp[capacity][length-1] != -1)
        return dp[capacity][length-1];
    
        
    if(weight[length-1] <= capacity)
        return dp[capacity][length-1] = max(profit[length-1]+knapsackProblem(weight,profit,length-1,capacity-weight[length-1]),
                                    knapsackProblem(weight,profit,length-1,capacity));
                                    
    return knapsackProblem(weight,profit,length-1,capacity);
}



int main()
{
    memset(dp,-1,sizeof(dp));
    
	int profit[] = { 60, 100, 120, 300, 25 };
	int weight[] = { 10, 20, 30, 40, 50 };
    
    int size = sizeof(weight)/sizeof(int);
    int capacity = 100;
    
    cout<<knapsackProblem(weight,profit,size,capacity);
}
