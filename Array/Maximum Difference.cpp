#include <bits/stdc++.h>
using namespace std;

void maxDifference(int array[], int size)
{
    int maximum_difference = array[1]-array[0];
    int currrent_minimum = array[0];
    
    for(int i=1;i<size;i++)
    {
        maximum_difference = max(maximum_difference, array[i]-currrent_minimum);
        currrent_minimum = min(currrent_minimum,array[i]);
    }
    
    cout<<maximum_difference;
}


void maxDifference(int array[], int size)
{
    int maximum_difference = 0;
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(array[j]-array[i] > maximum_difference)
            maximum_difference = array[j]-array[i];
        }
    }
    
    cout<<maximum_difference;
}

int main()
{
    int array[] = {7,9,5,6,3,2};
    int size = sizeof(array)/sizeof(int);
    maxDifference(array,size);
    
    //for(int i=0; i<size; i++)
        //cout<<array[i]<<" "; 
}
