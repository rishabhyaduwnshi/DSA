#include <bits/stdc++.h>
using namespace std;

/* 
    - We carry one extra parameter sum_when_printing whoes current value is the sum of subsequence which we have to print
    - When we are adding an element in vector, we subtract that element from sum_when_printing
    - When sum_when_printing becomes 0, we print the subsequence
*/



void printSubsequence(int array[], vector<int> &vc, int current_index, int size, int sum_when_printing)
{
    if(current_index == size)
    {
        if(sum_when_printing == 0)
        for(int x : vc)
            cout<<x<<" ";
        cout<<endl;
        return;
    }
    
    vc.push_back(array[current_index]);
    printSubsequence(array,vc,current_index+1,size,sum_when_printing-array[current_index]);
    vc.pop_back();
    printSubsequence(array,vc,current_index+1,size,sum_when_printing);
}


int main()
{
    int array[] = {1,2,1};
    int sum_when_printing = 2;
    vector<int> vc;
    printSubsequence(array,vc,0,3,sum_when_printing);
}
