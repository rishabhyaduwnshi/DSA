#include<bits/stdc++.h>
using namespace std;

//most of the questions related to subset are based on this

void printSubsequences(int array[], vector<int> result, int size, int current_index)
{
    if(current_index == size)
    {
        for(int x : result)
            cout<<x<<" ";
        cout<<endl;
        return;
    }
    
    result.push_back(array[current_index]);
    printSubsequences(array,result,size,current_index+1);
    result.pop_back();
    printSubsequences(array,result,size,current_index+1);
}


int main()
{
    int array[] = {3,1,2,4};
    int size = sizeof(array)/sizeof(int);
    vector<int> result;
    
    printSubsequences(array,result,size,0);
}
