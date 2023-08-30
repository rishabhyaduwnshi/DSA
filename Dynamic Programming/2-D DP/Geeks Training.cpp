//https://practice.geeksforgeeks.org/problems/geeks-training/1
//memoization
int maxPoints(vector<vector<int>> &points, int current_day, int last_index_used, vector<vector<int>> &results)
{
        
    if(results[current_day][last_index_used] != -1)
        return results[current_day][last_index_used];
        
    if(current_day == 0)
    {
        int current_max = 0;
        for(int current_index=0;current_index<3;current_index++)
        {
            if(current_index != last_index_used)
                current_max = max(current_max,points[0][current_index]);
        }
        return current_max;
    }
        
    int current_max = 0;
    for(int current_index = 0;current_index<3;current_index++)
    {
        if(current_index != last_index_used)
        {
            int point = points[current_day][current_index]+maxPoints(points,current_day-1,current_index,results);
            results[current_day][last_index_used] = current_max = max(current_max,point);
        }
    }
        
    return results[current_day][last_index_used];
}

int maximumPoints(vector<vector<int>>& points, int n) 
{
    vector<vector<int>> results(n,vector<int>(4,-1));
    return maxPoints(points,n-1,3,results);
}
