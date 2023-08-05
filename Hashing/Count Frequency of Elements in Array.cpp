#include <bits/stdc++.h>
using namespace std;


void findUniqueElements(int array[], int size)
{
    unordered_map<int,int> um;
    for(int i=0;i<size;i++)
        um[array[i]]++;
        
    for(auto x: um)
        cout<<x.first<<" "<<x.second<<"\n";
}


int main()
{
    int array[] = {1,2,3,4,5,6,3,2,1};
    int size = sizeof(array)/sizeof(int);
    findUniqueElements(array,size);
    
}
