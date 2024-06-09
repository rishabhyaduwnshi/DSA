int binary_search(vector<int> &nums, int left, int right)
{
    int minimum_number = INT_MAX;
    int index = -1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] >= nums[left])
        {
            if(minimum_number > nums[left])
            {
                index = left;
                minimum_number = nums[left];
            }
            left = mid + 1;
        }
        else
        {
            if(minimum_number > nums[mid])
            {
                index = mid;
                minimum_number = nums[mid];
            }
            right = mid - 1;
        }
    }
    
    return index;
}

int findKRotation(vector<int> &arr)
{
    int n = arr.size()-1;
    int result = binary_search(arr,0,n);
	    return result;  
}
