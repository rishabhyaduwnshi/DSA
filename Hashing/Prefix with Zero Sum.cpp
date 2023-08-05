#include <bits/stdc++.h>
using namespace std;


bool subArrayWithZeroSum(int array[], int size)
{
    unordered_set<int> us;
    int prefix_sum = 0;
    
    for(int i=0;i<size;i++)
    {
        prefix_sum += array[i];
        if(us.find(prefix_sum) != us.end())
            return true;
        if(prefix_sum == 0)
            return true;
        us.insert(array[i]);
    }
    
    return false;
}


int main()
{
    int array[] = {-3,4,-3,-1,1};
    int size = sizeof(array)/sizeof(int);
    int target_sum = 8;
    
    if(subArrayWithZeroSum(array,size))
        cout<<"Yes";
    else
        cout<<"No";
}
