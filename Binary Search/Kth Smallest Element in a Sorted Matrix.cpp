int upper_bound_value(vector<int> &matrix, int m, int value)
    {
        int start = 0;
        int end = m-1;

        while(start <= end)
        {
            int mid = (start+end)/2;
            if(matrix[mid] <= value)
                start = mid+1;
            else
                end = mid-1;
        }

        return start;
    }

    int find_smaller_count(vector<vector<int>>& matrix, int n, int m, int value)
    {
        int count = 0;
        for(int i=0;i<n;i++)
        {
            count += upper_bound_value(matrix[i],m,value);
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int smallest = 1e9;
        int largest = -1e9;

        for(int i=0;i<n;i++)
        {
            smallest = min(smallest,matrix[i][0]);
            largest = max(largest,matrix[i][m-1]);
        }

        while(smallest <= largest)
        {
            long long mid = (smallest+largest)/2;
            int smaller_value_count = find_smaller_count(matrix,m,n,mid);
            cout<<mid<<" "<<smaller_value_count<<endl;
            if(smaller_value_count >= k)
                largest = mid-1;
            else
                smallest = mid+1;
        }

        return smallest;
    }
