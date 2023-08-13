#include <bits/stdc++.h>
using namespace std;

int memoized_array[1001][1001];

int knapSack(int weight[], int profit[],int capacity, int size)
{
    if(capacity == 0 || size == 0)
        return 0;
    
    if(memoized_array[capacity][size] == -1)
    {
        if(capacity >= weight[size-1])
        return memoized_array[capacity][size] =  max(profit[size-1] + knapSack(weight,profit, capacity-weight[size-1],size-1),
                                    knapSack(weight,profit,capacity,size-1));
        else
            return memoized_array[capacity][size] = knapSack(weight,profit,capacity,size-1);
    }
    else
        return memoized_array[capacity][size];
}


int main()
{
    memset(memoized_array,-1,sizeof(memoized_array));
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int capacity = 50;
    int size = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(weight, profit, capacity, size);
    return 0;
}
