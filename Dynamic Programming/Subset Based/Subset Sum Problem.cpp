int memoized_array[1000][1000];

int SubsetSum(vector<int> array, int size, int target_sum)
{
    if(target_sum == 0)
        return 1;

    if(size == 0 )
        return 0;
        
    if(memoized_array[size-1][target_sum] != -1)
        return memoized_array[size-1][target_sum];
        
    if(array[size-1] > target_sum)
        return memoized_array[size-1][target_sum] = SubsetSum(array, size-1, target_sum);
    else
        return memoized_array[size-1][target_sum] = SubsetSum(array, size-1, target_sum - array[size-1]) 
                || SubsetSum(array, size-1, target_sum);
    }
    
bool isSubsetSum(vector<int>arr, int sum)
{
    memset(memoized_array,-1,sizeof(memoized_array));
    int result = SubsetSum(arr,arr.size(),sum);
        
    if(result == 0)
        return false;
    else
        return true;
}
