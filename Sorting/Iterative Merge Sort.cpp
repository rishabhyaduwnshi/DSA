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


void iterativeMergeSort(int array[], int size)
{
    int p,low,high,mid,i;
    for(p=2;p<=size;p=p*2)
    {
        for(int i=0;i+p-1<size;i=i+p)
        {
            low = i;
            high = i+p-1;
            mid = (low+high)/2;
            merge(array,low,mid,high);
        }
    }
    
    if(p/2 < size)
        merge(array,0,p/2-1,size);
}


int main()
{
    int array[] = {2,1,3,10,8,6,9,4,5,7};
    int size = sizeof(array)/sizeof(int);
    iterativeMergeSort(array,size);
    for(int i=0;i<size;i++)
        cout<<array[i]<<" ";
}
