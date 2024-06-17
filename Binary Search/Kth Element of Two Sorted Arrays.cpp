int kthElement(vector<int> &nums1, vector<int>& nums2, int n, int m, int k)
{
    int length_n1 = nums1.size();
    int length_n2 = nums2.size();

    if (length_n1 > length_n2) 
    {
        return kthElement(nums2, nums1,m,n,k);
    }

    int start = max(0, k - length_n2);
    int end = min(k, length_n1);

    while (start <= end) 
    {
        int partition_X = (start + end) / 2;
        int partition_Y = k - partition_X;

        int max_leftX = (partition_X == 0) ? INT_MIN : nums1[partition_X - 1];
        int min_rightX = (partition_X == length_n1) ? INT_MAX : nums1[partition_X];

        int max_leftY = (partition_Y == 0) ? INT_MIN : nums2[partition_Y - 1];
        int min_rightY = (partition_Y == length_n2) ? INT_MAX : nums2[partition_Y];

        if (max_leftX <= min_rightY && max_leftY <= min_rightX) 
        {
            return max(max_leftX, max_leftY);
        } 
        else if (max_leftX > min_rightY)
        {
            end = partition_X - 1;
        } 
        else 
        {
            start = partition_X + 1;
        }
    }
}
