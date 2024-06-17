bool is_present(vector<int> array, int m, int target)
    {
        if(array[0] > target || array[m-1] < target)
            return false;

        int start = 0;
        int end = m-1;

        while(start <= end)
        {
            int mid = (start+end)/2;
            if(array[mid] == target)
                return true;
            else if(array[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++)
        {
            if(is_present(matrix[i],m,target) == true)
                return true;
        }

        return false;
    }
