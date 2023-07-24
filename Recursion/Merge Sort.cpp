#include <bits/stdc++.h>
using namespace std;

vector<int> vc = {0};
void merge(int array[], int low, int mid, int high)
{
    int left = low;
    int right = mid+1;
        
    while(left <= mid && right <= high)
    {
        if(array[left] <= array[right])
        { 
            vc.push_back(array[left]);
            left++;
        }
        else
        {
            vc.push_back(array[right]);
            right++;
        }
        
    }
    
    while(left <= mid)
    {
        vc.push_back(array[left]);
        left++;
    }
    
    while(right <= high)
    {
        vc.push_back(array[high]);
        high++;
    }
}

void mergeSort(int array[], int low, int high)
{
    if(low == high)
        return;
    
    int mid = (low+high)/2;
    mergeSort(array,low,mid);
    mergeSort(array,mid+1,high);
    merge(array,low,mid,high);
}



int main()
{
    int array[] = {2,1,3,4};
    int size = sizeof(array)/sizeof(int);
    int low = 0;
    int high = size-1;
    
    mergeSort(array,low,high);
    for(int x : vc)
        cout<<x<<" ";
}
