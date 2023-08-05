#include <bits/stdc++.h>
using namespace std;


int recursiveBinarySearch(int array[], int element, int low, int high)
{
    
    int mid = (low+high)/2;
    if(array[mid] > element)
        return recursiveBinarySearch(array,element,low,mid-1);
    else if(array[mid] < element)
        return recursiveBinarySearch(array,element,mid+1,high);
    else
    {
        if(mid == high+1 || array[mid+1] != array[mid])
            return mid;
        else
            return recursiveBinarySearch(array,element,mid+1,high);
    }
    
    return -1;
}

int main()
{
    int array[] = {10,20,30,30,30,40,50};
    int size = sizeof(array)/sizeof(int);
    cout<<recursiveBinarySearch(array,30,0,size-1);
}
