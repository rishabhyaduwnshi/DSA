int findMinimumDifference(int array[], int size, int current_sum, int total_sum, vector<vector<int>> &results)
{
    if(size == 0)
        return abs((total_sum-current_sum) - current_sum);
        
    if(results[size][current_sum] != -1)
        return results[size][current_sum];
            
    int take = findMinimumDifference(array,size-1,current_sum+array[size-1],total_sum,results);
    int not_take = findMinimumDifference(array,size-1,current_sum,total_sum,results);
    return results[size][current_sum] = min(take,not_take);
}
    
int minDifference(int arr[], int n)  
{ 
    int current_sum = 0;
	int total_sum = 0;
	for(int i=0;i<n;i++)
	    total_sum += arr[i];
	        
	vector<vector<int>> results(n+1, vector<int>(total_sum+1,-1));
	return findMinimumDifference(arr,n,current_sum,total_sum, results);
} 
