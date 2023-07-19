#include <bits/stdc++.h>
using namespace std;

/* We pass an empty vector in the function call. For every element in the array, we do two things
  - add the current_element to the vector and call the printSubsequence function
  - remove that element from the vector
  - call with adding printSubsequence again after removing current_element
  - with every function call, increment the current_index */



void printSubsequence(int array[], vector<int> &vc, int current_index, int size)
{
    if(current_index == size)
    {
        for(int x : vc)
            cout<<x<<" ";
        cout<<endl;
        return;
    }
    
    vc.push_back(array[current_index]);
    printSubsequence(array,vc,current_index+1,size);
    vc.pop_back();
    printSubsequence(array,vc,current_index+1,size);
}


int main()
{
    int array[] = {2,1,3};
    vector<int> vc;
    printSubsequence(array,vc,0,3);
}
