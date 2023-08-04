#include <bits/stdc++.h>
using namespace std;

void leaderInArray(int array[], int size)
{
    int current_leader = array[size-1];
    cout<<current_leader<<" ";
    for(int i=size-2; i>=0; i--)
    {
        if(array[i] > current_leader)
        {
            current_leader = array[i];
            cout<<current_leader<<" ";
        }
        
    }
}

void leaderInArray(int array[], int size)
{
    for(int i=0; i<size; i++)
    {
        bool isGreatest = true;
        for(int j=i+1; j<size; j++)
        {
            if(array[j] >= array[i])
                isGreatest = false;
        }
        
        if(isGreatest)
            cout<<array[i]<<" ";
    }
}

int main()
{
    int array[] = {10,5,1};
    int size = sizeof(array)/sizeof(int);
    leaderInArray(array,size);
    
    //for(int i=0; i<size; i++)
        //cout<<array[i]<<" "; 
}
