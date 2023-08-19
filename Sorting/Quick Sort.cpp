#include<bits/stdc++.h>
using namespace std;

int partition(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low;
    int j = high;
    
    do
    {
        do{i++;}while(array[i] <= pivot);
        do{j--;}while(array[j] > pivot);
        
        if(i<j)
            swap(array[i],array[j]);
    }
    while(i<j);
    swap(array[low],array[j]);
    
    return j;
}

void quickSort(int array[], int low, int high)
{
    int j;
    if(low < high)
    {
        j = partition(array,low,high);
        quickSort(array,low,j);
        quickSort(array,j+1,high);
    }
}


int main()
{
    int array[] = {2,1,3,12,8,6,9,4,5,7,13,0,INT_MAX};
    int size = sizeof(array)/sizeof(int);
    quickSort(array,0,size-1);
    for(int i=0;i<size-1;i++)
        cout<<array[i]<<" ";
}
