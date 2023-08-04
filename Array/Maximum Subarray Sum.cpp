#include <bits/stdc++.h>
using namespace std;

void maxSubarraySum(int array[], int size)
{
    int max_ending = array[0];
    int result = array[0];
    
    for(int i=1;i<size;i++)
    { 
        max_ending = max(array[i],max_ending+array[i]);
        result = max(result,max_ending);
    }
    
    cout<<result;
}

int main()
{
    int array[] = {-3,8,-2,4,-5,6};
    int size = sizeof(array)/sizeof(int);
    maxSubarraySum(array,size);
}
