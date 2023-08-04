#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(int array[], int size)
{
    int result = 1;
    for(int i=1; i<size; i++)
    {
        if(array[i] != array[result-1])
        {
            array[result] = array[i];
            result++;
        }
    }
}


int main()
{
    int array[] = {1,1,2,2,2,3,3,3,4,4,4,4,4};
    int size = sizeof(array)/sizeof(int);
    
    removeDuplicates(array,size);
    
    for(int i=0; i<size; i++)
        cout<<array[i]<<" ";
    
}
