int upp_bound(vector<int> matrix, int m, int target)
    {
        int start = 0;
        int end = m-1;
        while(start <= end)
        {
            int mid = (start+end)/2;
            if(matrix[mid] <= target)
                start = mid+1;
            else
                end = mid-1;
        }
        
        return start;
    }

    
    int count_smaller_number(vector<vector<int>> &matrix, int n, int m, int mid)
    {
        int count = 0;
        for(int i=0;i<n;i++)
        {
            count += upp_bound(matrix[i],m,mid);
        }
        return count;
    }
    
    int median(vector<vector<int>> &matrix, int n, int m)
    {
        int smallest = INT_MAX;
        int greatest = -1;
        int smaller_count = 0;
        int req_numbers = (n*m)/2;
        
        for(int i=0;i<n;i++)
        {
            smallest = min(smallest,matrix[i][0]);
            greatest = max(greatest,matrix[i][m-1]);
        }
        
        while(smallest <= greatest)
        {
            int mid = (smallest+greatest)/2;
            smaller_count = count_smaller_number(matrix,n,m,mid);
            if(smaller_count <= req_numbers)
                smallest = mid+1;
            else
                greatest = mid-1;
        }
        
        return smallest;
    }
