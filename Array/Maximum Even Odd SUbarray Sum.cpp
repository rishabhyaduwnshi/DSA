#include <bits/stdc++.h>
using namespace std;


void longestEvenOddSubArray(int array[], int size)
{
    int current_max = 1;
    int result = 1;
    for(int i=1;i<size;i++)
    {
        if((array[i]%2 == 0 && array[i-1]%2 == 1) || (array[i]%2 == 1 && array[i-1]%2 == 0))
        {
            current_max++;
            result = max(result,current_max);
        }
        else
        {
            current_max = 1;
        }
    }
    
    cout<<current_max<<" ";
}



int main()
{
    int array[] = {5,10,20,6,3,8};
    int size = sizeof(array)/sizeof(int);
    longestEvenOddSubArray(array,size);
    return 0;
}
