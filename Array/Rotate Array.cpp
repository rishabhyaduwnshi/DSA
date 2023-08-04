#include <bits/stdc++.h>
using namespace std;


void reverse(int array[], int start, int end)
{
    int temp;
    while(start <= end)
    {
        temp = array[start]; 
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}



void rotateArray(int array[], int size, int rotate_by)
{
    reverse(array,0,rotate_by-1);
    reverse(array,rotate_by,size-1);
    reverse(array,0,size-1);
}

int main()
{
    int array[] = {1,2,3,4,5};
    int size = sizeof(array)/sizeof(int);
    rotateArray(array,size,2);
    
    for(int i=0; i<size; i++)
        cout<<array[i]<<" "; 
}
