int binary_search(vector<int> &nums, int left, int right)
    {
        int minimum_number = INT_MAX;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(nums[mid] >= nums[left])
            {
                minimum_number = min(minimum_number,nums[left]);
                left = mid+1;
            }
            else
            {
                minimum_number = min(minimum_number,nums[mid]);
                right = mid-1;
            }
        }

        return minimum_number;

    }

    int findMin(vector<int>& nums) 
    {
        int n = nums.size()-1;
        return binary_search(nums,0,n);
    }
