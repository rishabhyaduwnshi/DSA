#include <bits/stdc++.h>
using namespace std;

/* 
    - When we get first subsequence, return true
    - When current_index reaches last possible index and still haven't found the subsequence, return false
*/



bool printSubsequence(int array[], vector<int> &vc, int current_index, int size, int sum_when_printing)
{
    if(current_index == size)
    {
            if(sum_when_printing == 0)
            {
                for(int x : vc)
                    cout<<x<<" ";
                    cout<<endl;
                return true;
            }
            else
                return false;
        
    }
    
    vc.push_back(array[current_index]);
    if(printSubsequence(array,vc,current_index+1,size,sum_when_printing-array[current_index]))
        return true;
    vc.pop_back();
    
    if(printSubsequence(array,vc,current_index+1,size,sum_when_printing))
        return true;
        
    return false;
}


int main()
{
    int array[] = {1,2,1};
    int sum_when_printing = 2;
    vector<int> vc;
    printSubsequence(array,vc,0,3,sum_when_printing);
}
