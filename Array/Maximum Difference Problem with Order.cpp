#include <bits/stdc++.h>
using namespace std;

void maximum_difference(int array[], int size)
{
    int current_result = array[1]-array[0];
    int current_min = array[0];
    
    for(int i=1;i<size;i++)
    {
        current_result = max(current_result,array[i]-current_min);
        current_min = min(current_min,array[i]);
    }
    
    cout<<current_result;
    
}

int main()
{
    int array[] = {30,10,8,2};
    int size = sizeof(array)/sizeof(int);
    maximum_difference(array,size);
}
