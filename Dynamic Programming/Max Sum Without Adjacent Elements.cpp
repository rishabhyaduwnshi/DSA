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
