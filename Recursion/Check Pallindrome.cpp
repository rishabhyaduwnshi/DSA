#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(int array[], int leftIndex, int rightIndex)
{
    if(leftIndex > rightIndex)
        return true;
        
    if(array[leftIndex] != array[rightIndex])
        return false;
        
    return isPallindrome(array,leftIndex+1,rightIndex-1);
}


int main()
{
    int array[] = {2,1};
    int size = sizeof(array)/sizeof(int);
    
    if(isPallindrome(array,0,size-1))
        cout<<"Yes";
    else
        cout<<"No";
    
}
