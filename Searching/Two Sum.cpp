#include <bits/stdc++.h>
using namespace std;

bool twoSum(int array[], int size, int target_sum)
{
    int i=0;
    int j=size-1;
    
    while(i < j)
    {
        int sum = array[i]+array[j];
        if(sum == target_sum)
            return true;
            
        else if(sum > target_sum)
            j--;
        else
            i++;
    }
    
    return false;
}

int main()
{
    int array[] = {10,20,30,40,50};
    int size = sizeof(array)/sizeof(int);
    if(twoSum(array,size,60))
        cout<<"Yes";
    else
        cout<<"No";
}
