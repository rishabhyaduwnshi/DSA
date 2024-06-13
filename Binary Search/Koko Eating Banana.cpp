bool is_possible(vector<int>& piles, int speed, int allowed_time)
    {
        long long hours = 0;
        for(int i=0;i<piles.size();i++)
        {
            hours += ceil(double(piles[i])/double(speed));
        }

        return hours <= allowed_time;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        long max_num = *max_element(piles.begin(),piles.end());
        long low = 1;
        long high = max_num;
        long answer = max_num;

        while(low <= high)
        {
            int mid = (low+high)/2;
            if(is_possible(piles,mid,h))
            {
                answer = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }

        return answer;
    }
