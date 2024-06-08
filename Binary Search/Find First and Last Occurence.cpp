int left_occurence(int nums[], int target, int n)
    {
        int left = 0;
        int right = n-1;
        int result = -1;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target)
            {
                result = mid;
                right = mid-1;
            }
            else if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }

        return result;
    }

    int right_occurence(int nums[], int target, int n)
    {
        int left = 0;
        int right = n-1;
        int result = -1;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target)
            {
                result = mid;
                left = mid+1;
            }
            else if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }

        return result;
    }
