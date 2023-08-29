//bottom-up approach
int findMaxSum(int *arr, int n) 
{
	vector<int> results(n,0);
	for(int i=0;i<n;i++)
	{
	    int pick_current = arr[i];
	    int not_pick_current = INT_MIN;
	        
	    if(i>0)
	        not_pick_current = results[i-1];
	   
	    if(i>1)
	        pick_current = arr[i]+results[i-2];
	    
	    results[i] = max(pick_current, not_pick_current);
	 }
	    
    return results[n-1];
}

//top-down approach
int maxSum(vector<int> &array, int current_index,vector<int> &results)
{
    if(results[current_index] != -1)
	    return results[current_index];
	        
	if(current_index == 0)
	    return array[current_index];
	        
	if(current_index < 0)
	    return 0;
	        
	int pick_current = array[current_index]+maxSum(array,current_index-2,results);
	int not_pick_current = maxSum(array,current_index-1,results);
	    
	return results[current_index] = max(pick_current,not_pick_current);
}

int findMaxSum(int *arr, int n) 
{
    vector<int> array;
    vector<int> results(n+1,-1);
	    
    for(int i=0;i<n;i++)
        array.push_back(arr[i]);
	return maxSum(array,n-1,results);
}
