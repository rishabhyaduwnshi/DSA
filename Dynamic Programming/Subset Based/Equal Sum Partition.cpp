int SubsetSum(vector<int> array, int size, int target_sum, vector<vector<int>> &memoized_array)
{
    if(target_sum == 0)
        return 1;

    if(size == 0 )
        return 0;
        
    if(memoized_array[size-1][target_sum] != -1)
        return memoized_array[size-1][target_sum];
        
    if(array[size-1] > target_sum)
        return memoized_array[size-1][target_sum] = SubsetSum(array, size-1, target_sum,memoized_array);
    else
        return memoized_array[size-1][target_sum] = SubsetSum(array, size-1, target_sum - array[size-1],memoized_array) 
            || SubsetSum(array, size-1, target_sum,memoized_array);
    }

bool canPartition(vector<int>& nums) 
{
    int sum = 0;
    for(int i=0;i<nums.size();i++)
        sum += nums[i];

    if(sum%2 == 1)
        return false;
    else
    {
        vector<vector<int>> memoized_array(nums.size() + 1,vector<int>(sum + 1,-1));
        int result = SubsetSum(nums, nums.size(), (sum/2),memoized_array);
        if(result == 1)
            return true;
        else
            return false;
    }
        
}
