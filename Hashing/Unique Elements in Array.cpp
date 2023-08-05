#include <bits/stdc++.h>
using namespace std;


void findUniqueElements(int array[], int size)
{
    unordered_set<int> us;
    for(int i=0;i<size;i++)
    us.insert(array[i]);
    
    cout<<us.size();
}


int main()
{
    int array[] = {1,2,3,4,1,3,5};
    int size = sizeof(array)/sizeof(int);
    findUniqueElements(array,size);
    
}
