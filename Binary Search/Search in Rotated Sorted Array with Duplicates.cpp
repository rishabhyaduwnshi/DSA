bool binary_search(vector<int> &nums, int left, int right, int target)
    {
        
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target)
                return true;
            if(nums[left] == nums[mid] && nums[mid] == nums[right])
            {
                left++;
                right--;
                continue;
            }

            //find the sorted half
            if(nums[left] <= nums[mid])
            {
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

        return false;
    }

    bool search(vector<int>& nums, int target) 
    {
        int n = nums.size()-1;
        return binary_search(nums,0,n,target);
    }
