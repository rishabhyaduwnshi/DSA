#include <bits/stdc++.h>
using namespace std;


void maxSubArraySumOfSizeK(int array[], int k, int size)
{
    int current_subarray_sum = 0;
    for(int i=0;i<k;i++)
        current_subarray_sum += array[i];
        
    int max_sum = current_subarray_sum;
    for(int i=k;i<size;i++)
        current_subarray_sum = current_subarray_sum+array[i]-array[i-k];
        max_sum = max(max_sum, current_subarray_sum);
        
    cout<<max_sum;
}


int main()
{
    int array[] = {1,8,30,-5,20,7};
    int size = sizeof(array)/sizeof(int);
    maxSubArraySumOfSizeK(array,4,size);
    return 0;
}
