int countSubsets(int array[], int current_index, int current_sum, int size, int sum, vector<vector<int>> &results)
{
	if(current_index == size)
	{
	    if(current_sum == sum)
	        return 1;
	    else
	        return 0;
	}
	    
	if(results[current_index][current_sum] != -1)
	    return results[current_index][current_sum];
	    
	int not_take = countSubsets(array,current_index+1,current_sum,size,sum,results)%1000000007;
	int take = 0;
	    
	if(array[current_index] <= sum-current_sum)
	    take = countSubsets(array,current_index+1,current_sum+array[current_index],size,sum,results)%1000000007;
	    
	return results[current_index][current_sum] = (take+not_take)%1000000007;
}
	
int perfectSum(int arr[], int n, int sum)
{
	vector<vector<int>> results(n+1,vector<int>(sum+1,-1));
    return countSubsets(arr,0,0,n,sum,results);
}
