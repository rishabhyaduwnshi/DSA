#include <bits/stdc++.h>
using namespace std;

void frequenciesInSortedArray(int array[], int size)
{
    int count=1;
    int i=1;
    for(i=1; i<size; i++)
    {
        if(array[i] != array[i-1])
        {
            cout<<"Frequency of "<<array[i-1]<<" is "<<count<<"\n";
            count = 0;
        }
        count++;
    }
    
    cout<<"Frequency of "<<array[i-1]<<" is "<<count<<"\n";
}

int main()
{
    int array[] = {1,2,2,3,3,3,4,5,6,6};
    int size = sizeof(array)/sizeof(int);
    frequenciesInSortedArray(array,size);
    
    //for(int i=0; i<size; i++)
        //cout<<array[i]<<" "; 
}
