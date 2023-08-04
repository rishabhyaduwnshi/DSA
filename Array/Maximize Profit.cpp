#include <bits/stdc++.h>
using namespace std;

void maximizeProfit(int array[], int size)
{
    int profit = 0;
    for(int i=1; i<size; i++)
    {
        if(array[i] > array[i-1])
        {
            profit += (array[i]-array[i-1]);
        }
    }
    
    cout<<profit;
}

int main()
{
    int array[] = {1,5,3,8,12};
    int size = sizeof(array)/sizeof(int);
    maximizeProfit(array,size);
    
    //for(int i=0; i<size; i++)
        //cout<<array[i]<<" "; 
}
