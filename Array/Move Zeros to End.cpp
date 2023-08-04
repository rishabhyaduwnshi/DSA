#include <bits/stdc++.h>
using namespace std;


void moveZerosToEnd(int array[], int size)
{
    int non_zero_count = 0;
    for(int i=0; i<size; i++)
    {
        if(array[i] != 0)
        {
            swap(array[i],array[non_zero_count]);
            non_zero_count++;
        }
    }
}

void moveZerosToEnd(int array[], int size)
{
    for(int i=0; i<size; i++)
    {
        if(array[i] == 0)
        {
            for(int j=i+1;j<size; j++)
            {
                if(array[j] != 0)
                 {   
                     swap(array[i],array[j]);
                     break;
                 }
            }
        }
    }
}



int main()
{
    int array[] = {1,2,0,0,3,7,2,0,1,2};
    int size = sizeof(array)/sizeof(int);
    moveZerosToEnd(array,size);
    
    for(int i=0; i<size; i++)
        cout<<array[i]<<" "; 
}
