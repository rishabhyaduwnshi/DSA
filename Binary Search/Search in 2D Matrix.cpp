bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int start = 0;
        int end = (n*m)-1;

        while(start <= end)
        {
            int mid = (start+end)/2;
            int i = mid/m;
            int j = mid%m;

            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                end = mid-1;
            else
                start = mid+1;
        }

        return false;
    }
