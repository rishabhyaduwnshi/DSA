#include <bits/stdc++.h>
using namespace std;


void majorityElement(int array[], int size)
{
    int result = 0;
    int count = 1;
    
    for(int i=1;i<size;i++)
    {
        if(array[result] == array[i])
            count++;
        else
            count--;
        
        if(count == 0)
        {    
            result = i;
            count = 1;
        }
    }
    
    count = 0;
    for(int i=0;i<size;i++)
    {
        if(array[i] == array[result])
            count++;
    }
    
    if(count > (size/2))
        cout<<array[result];
    else
        cout<<-1;
}



int main()
{
    int array[] = {1,2,1,1,2,3,4,1,1};
    int size = sizeof(array)/sizeof(int);
    majorityElement(array,size);
    return 0;
}
