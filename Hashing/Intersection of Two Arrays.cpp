#include <bits/stdc++.h>
using namespace std;


void intersetionOfTwoArrays(int array1[], int size1, int array2[], int size2)
{
    unordered_set<int> us(array2,array2+size2);
    for(int i=0;i<size1;i++)
    {
        if(us.count(array1[i]) == 1)
            cout<<array1[i]<<" ";
    }
}


int main()
{
    int array1[] = {1,2,3,4,5,6};
    int size1 = sizeof(array1)/sizeof(int);
    
    int array2[] = {1,2,3};
    int size2 = sizeof(array2)/sizeof(int);
    
    intersetionOfTwoArrays(array1,size1,array2,size2);
    
}
