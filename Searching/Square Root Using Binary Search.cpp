#include <bits/stdc++.h>
using namespace std;

int squareRoot(int number)
{
    int low = 1;
    int high = number;
    int result = -1;
    
    while(low <= high)
    {
        int mid = (low+high)/2;
        int midSquare = mid*mid;
        
        if(midSquare == number)
            return mid;
        else if(midSquare > number)
            high = mid-1;
        else
           { low = mid+1;
            result = mid;}
    }
    
    return result;
}

int main()
{
    int array[] = {10,20,30,30,30,40,50};
    int size = sizeof(array)/sizeof(int);
    //cout<<recursiveBinarySearch(array,30,0,size-1);
    
    cout<<squareRoot(17);
}
