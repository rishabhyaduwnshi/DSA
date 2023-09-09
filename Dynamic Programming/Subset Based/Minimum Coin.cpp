//Minimum coin required
//https://practice.geeksforgeeks.org/problems/min-coin5549/1

int mCoins(vector<int> &nums, int current_index, int current_amount, int total_amount, vector<vector<int>> &results)
{
    if(current_index == 0)
	{
	    if((total_amount-current_amount)%nums[0] == 0)
	        return (total_amount-current_amount)/nums[0];
	    return 1e9;
	}
	   
	if(results[current_index][total_amount-current_amount] != -1)
	    results[current_index][total_amount-current_amount];
	   
	 int not_take = 0 + mCoins(nums,current_index-1,current_amount,total_amount, results);
	 int take = INT_MAX;
	   
	 if(nums[current_index] <= total_amount-current_amount)
	    take = 1 + mCoins(nums,current_index,current_amount+nums[current_index],total_amount, results);
	        
	 return results[current_index][total_amount-current_amount] =  min(take,not_take);
}
	
	
int MinCoin(vector<int>nums, int amount)
{
    vector<vector<int>> results(nums.size(), vector<int>(amount+1,-1));
	int result = mCoins(nums,nums.size()-1,0,amount, results);
	if(result >= 1e9)
	    return -1;
	else
	    return result;
}
