int longestSubarrayWithSumK(vector<int> a, long long k) 
{
    map<long long, int> pre_sum;
    int current_sum = 0;
    int max_length = 0;
    for(int i=0;i<a.size();i++)
    {
        current_sum += a[i];
        if(current_sum == k)
            max_length = max(max_length,i+1);

        long long rem = current_sum-k;
        if(pre_sum.find(rem) != pre_sum.end())
        {
            int len = i - pre_sum[rem];
            max_length = max(max_length,len);
        }
        if(pre_sum.find(current_sum) == pre_sum.end())
            pre_sum[current_sum] = i;
    }

    return max_length;
}
