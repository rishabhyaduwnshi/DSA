double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int length_n1 = nums1.size();
    int length_n2 = nums2.size();

    // Ensure that nums1 is the smaller array
    if (length_n1 > length_n2)
        return findMedianSortedArrays(nums2, nums1);

    int start = 0;
    int end = length_n1;

    while (start <= end) 
    {
        int partition_X = (start + end) / 2;
        int partition_Y = (length_n1 + length_n2 + 1) / 2 - partition_X;

        int max_leftX = (partition_X == 0) ? INT_MIN : nums1[partition_X - 1];
        int min_rightX = (partition_X == length_n1) ? INT_MAX : nums1[partition_X];

        int max_leftY = (partition_Y == 0) ? INT_MIN : nums2[partition_Y - 1];
        int min_rightY = (partition_Y == length_n2) ? INT_MAX : nums2[partition_Y];

        if (max_leftX <= min_rightY && max_leftY <= min_rightX) 
        {
            if ((length_n1 + length_n2) % 2 == 0)
                return (double)(max(max_leftX, max_leftY) + min(min_rightX, min_rightY)) / 2.0;
            else
                return (double)max(max_leftX, max_leftY);
        } 
        else if (max_leftX > min_rightY)
            end = partition_X - 1;
        else
            start = partition_X + 1;
    }

    return 0.0; 
}
