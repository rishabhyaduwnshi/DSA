bool cows_placed(vector<int> &stalls, int k, int distance)
{
    int cows_placed_count = 1;
    int last_placed_position = stalls[0];

    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i] - last_placed_position >= distance)
        {
            cows_placed_count++;
            last_placed_position = stalls[i];
        }
    }

    if(cows_placed_count >= k)
        return true;
    else
        return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());

    int start = 1;
    int end = (*max_element(stalls.begin(),stalls.end())) - (*min_element(stalls.begin(),stalls.end()));
    int result = INT_MIN;

    while(start <= end)
    {
        int mid = (start+end)/2;
        if(cows_placed(stalls,k,mid) == true)
        {
            result = max(result,mid);
            start = mid+1;
        }
        else
            end = mid-1;
    }

    return result;
}
