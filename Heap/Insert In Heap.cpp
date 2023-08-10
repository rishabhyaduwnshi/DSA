#include<bits/stdc++.h>
using namespace std;

void insertInHeap(int array[], int n)
{
    int i=n, temp;
    temp = array[i];
    
    while(i>1 && temp > array[i/2])
    {
        array[i] = array[i/2];
        i = i/2;
    }
    array[i] = temp;
}

int main()
{
    int array[] = {0,10,20,30,25,5,40,35};
    int size = sizeof(array)/sizeof(int);
    
    for(int i=2;i<=size;i++)
        insertInHeap(array,i);
        
    for(int i=1;i<size;i++)
        cout<<array[i]<<" ";
}
