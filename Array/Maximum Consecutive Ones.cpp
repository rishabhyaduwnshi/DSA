#include <bits/stdc++.h>
using namespace std;

void maxConsecutiveOnes(int array[], int size)
{
    int current_max = 0;
    int count = 0;
    for(int i=0;i<size;i++)
    {
        if(array[i] == 1)
        {
            count++;
            current_max = max(count,current_max);
        }
        else
        {
            count = 0;
        }
    }
    
    cout<<current_max;
    
}

int main()
{
    int array[] = {0,0,1,1,1,1,1,0,1,1,1,0,0,0,0};
    int size = sizeof(array)/sizeof(int);
    maxConsecutiveOnes(array,size);
    
    //for(int i=0; i<size; i++)
        //cout<<array[i]<<" "; 
}
