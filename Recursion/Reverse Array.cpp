#include <bits/stdc++.h>
using namespace std;

void reverseArray(int array[], int left_index, int right_index)
{
    if(left_index > right_index)
        return;
        
    swap(array[left_index],array[right_index]);
    reverseArray(array,left_index+1,right_index-1);
}


int main()
{
    int array[] = {1,2,3,4,5,6};
    int size = sizeof(array)/sizeof(int);
    
    reverseArray(array,0,size-1);
    for(int i=0;i<size;i++)
        cout<<array[i]<<" ";
}
