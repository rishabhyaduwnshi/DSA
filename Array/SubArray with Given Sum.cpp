#include <bits/stdc++.h>
using namespace std;


bool subArrayWithGivenSum(int array[], int size, int sum)
{
    int s = 0;
    int current = 0;
    
    for(int e=0;e<size;e++)
    {
        current += array[e];
        while(sum < current)
        {
            current -= array[s];
            s++;
        }
        
        if(current == sum)
            return true;
    }
    
    return false;
}


int main()
{
    int array[] = {4,8,12,5};
    int size = sizeof(array)/sizeof(int);
    int sum = 17;
    
    if(subArrayWithGivenSum(array,size,sum))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
