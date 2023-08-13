#include <bits/stdc++.h>
using namespace std;

int findMinimumDifference(int array[], int size, int current_sum, int total_sum, vector<vector<int>> &memoized_array)
{
    if(size == 0)
        return abs((total_sum-current_sum) - current_sum);
        
    if(memoized_array[size][current_sum] != -1)
        return memoized_array[size][current_sum];
        
    int take = findMinimumDifference(array,size-1,current_sum+array[size-1],total_sum,memoized_array);
    int not_take = findMinimumDifference(array,size-1,current_sum,total_sum,memoized_array);
    
    return memoized_array[size][current_sum] = min(take,not_take);
}


int main()
{
    int array[] = {3,9,7,3};
    int size = sizeof(array)/sizeof(int);
    int current_sum = 0;
    int total_sum = 0;
    
    for(int i=0;i<size;i++)
        total_sum += array[i];
    
    vector<vector<int>> memoized_array(size+1, vector<int>(total_sum+1,-1));
    
    cout<<findMinimumDifference(array,size,current_sum,total_sum, memoized_array);
}
