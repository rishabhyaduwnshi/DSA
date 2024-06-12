long long int floorSqrt(long long int x) 
{
        long long left = 1;
        long long right = x;
        long long answer = 1;
        
        while(left <= right)
        {
            long long mid = (left+right)/2;
            if(mid*mid > x)
                right = mid-1;
            else
            {
                answer = mid;
                left = mid+1;
            }
        }
        
        return answer;
}
