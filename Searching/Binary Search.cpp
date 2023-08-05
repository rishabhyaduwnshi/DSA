#include <bits/stdc++.h>
using namespace std;


int recursiveBinarySearch(int array[], int element, int low, int high)
{
    
    int mid = (low+high)/2;
    if(array[mid] == element)
        return mid;
    
    if(array[mid] > element)
        return recursiveBinarySearch(array,element,low,mid-1);
    else
        return recursiveBinarySearch(array,element,mid+1,high);
        
    
}



int iterativeBinarySearch(int array[], int size, int element)
{
   int low = 0;
   int high = size-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(array[mid] == element)
            return mid;
        else if(array[mid] > element)
            high = mid-1;
        else
            low = mid+1;
    }
    
    return -1;
}

int main()
{
    int array[] = {10,20,30,40,50};
    int size = sizeof(array)/sizeof(int);
    cout<<iterativeBinarySearch(array,size,40)<<endl;
    cout<<recursiveBinarySearch(array,40,0,size-1);
}
