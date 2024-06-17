int lower_bound(vector<int> array, int m)
    {
        int start = 0;
        int end = m-1;
        int count = 0;
        while(start <= end)
        {
            int mid = (start+end)/2;
            if(array[mid] == 1)
            {
                count = (m-mid);
                end = mid-1;
            }
            else
                start = mid+1;
        }
        
        return (count != 0) ? count : -1;
    }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
	{
	    int max_count = -1;
	    int index = -1;
	    for(int i=0;i<n;i++)
	    {
	        int current_count = lower_bound(arr[i],m);
	        if(current_count > max_count)
	        {    
	            max_count = current_count;
	            index = i;
	        }
	    }
	    
	    return index;
	}
