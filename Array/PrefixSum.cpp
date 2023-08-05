#include <bits/stdc++.h>
using namespace std;


int prefixSumArray[100] = {0};

void prefixSum(int array[], int size)
{
    prefixSumArray[0] = array[0];
    for(int i=1;i<size;i++)
        prefixSumArray[i] = prefixSumArray[i-1]+array[i];
}


int main()
{
    int array[] = {4,8,12,5};
    int size = sizeof(array)/sizeof(int);
    prefixSum(array,size);
    
    for(int i=0;i<size;i++)
        cout<<prefixSumArray[i]<<" ";    
}
