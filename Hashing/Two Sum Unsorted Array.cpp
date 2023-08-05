#include <bits/stdc++.h>
using namespace std;


bool twoSumUnsortedArray(int array[], int size, int target_sum)
{
    unordered_set<int> us;
    for(int i=0;i<size;i++)
    {
        if(us.count(target_sum-array[i]) == 1)
            return true;
        else
            us.insert(array[i]);
    }
    
    return false;
}


int main()
{
    int array[] = {1,2,3,4,5};
    int size = sizeof(array)/sizeof(int);
    int target_sum = 8;
    
    if(twoSumUnsortedArray(array,size,target_sum))
        cout<<"Yes";
    else
        cout<<"No";
}
