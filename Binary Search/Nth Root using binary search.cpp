int NthRoot(int n, int m)
	{
	    int left = 1;
	    int right = m;
	    
	    while(left <= right)
	    {
	        int mid = (left+right)/2;
	        if(pow(mid,n) == m)
	            return mid;
	        else if((pow(mid,n) > m))
	            right = mid-1;
	        else
	            left = mid+1;
	    }
	    
	    return -1;
	}  
