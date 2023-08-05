#include <bits/stdc++.h>
using namespace std;


int prefixSumArray[100] = {0};
int suffixSumArray[100] = {0};

void equlibriumPoint(int array[], int size)
{
    prefixSumArray[0] = array[0];
    for(int i=1;i<size;i++)
        prefixSumArray[i] = prefixSumArray[i-1]+array[i];
        
    suffixSumArray[size-1] = array[size-1];
    for(int i=size-2;i>=0;i--)
        suffixSumArray[i] = suffixSumArray[i+1]+array[i];
    
}


int main()
{
    int array[] = {3,4,8,-9,9,7};
    int size = sizeof(array)/sizeof(int);
    equlibriumPoint(array,size);
    
    for(int i=0;i<size; i++)
    {
        if(prefixSumArray[i] == suffixSumArray[i])
            cout<<array[i];
    }
}
