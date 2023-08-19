#include<bits/stdc++.h>
using namespace std;

void merge(int array[], int low, int mid, int high)
{
    int i=low,j=mid+1,k=low;
    int temp_array[100];
    
    while(i<=mid && j<=high)
    {
        if(array[i] < array[j])
            temp_array[k++] = array[i++];
        else
            temp_array[k++] = array[j++];
    }
    
    for(;i<=mid;i++)
        temp_array[k++] = array[i];
        
    for(;j<=high;j++)
        temp_array[k++] = array[j];
        
    for(int i=low;i<=high;i++)
        array[i] = temp_array[i];
}

void recursiveMergeSort(int array[],int low, int high)
{
    if(low < high)
    {
        int mid = floor((low+high)/2);
        recursiveMergeSort(array,low,mid);
        recursiveMergeSort(array,mid+1,high);
        merge(array,low,mid,high);
    }
}

int main()
{
    int array[] = {2,1,3,12,8,6,9,4,5,7,13,0};
    int size = sizeof(array)/sizeof(int);
    recursiveMergeSort(array,0,size-1);
    for(int i=0;i<size;i++)
        cout<<array[i]<<" ";
}
