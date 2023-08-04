#include <bits/stdc++.h>
using namespace std;

void trappingRainwaterProblem(int array[], int size)
{
    int result = 0;
    int left_max[size];
    left_max[0] = array[0];
    
    for(int i=1;i<size;i++)
        left_max[i] = max(array[i],left_max[i-1]);
    
    int right_max[size];
    right_max[size-1] = array[size-1];
    
    for(int i=size-2;i>=0;i--)
        right_max[i] = max(array[i],right_max[i+1]);
        
    for(int i=0;i<size;i++)
        result += min(left_max[i],right_max[i])-array[i];
        
    cout<<result;
}

int main()
{
    int array[] = {3,0,1,2,5};
    int size = sizeof(array)/sizeof(int);
    trappingRainwaterProblem(array,size);
    
    //for(int i=0; i<size; i++)
        //cout<<array[i]<<" "; 
}
