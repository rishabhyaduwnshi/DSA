int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target)
                return mid;

            //find the sorted half
            if(nums[left] <= nums[mid])
            {
                //move the pointer left/right
                if(nums[left] <= target && target <= nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                if(nums[mid] <= target && target <= nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        
        return -1;
    }
