/*
    *   
   ***  
  ***** 
 *******
*********

*/

#include <bits/stdc++.h>
using namespace std;

void print_pattern(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        
        
        for(int j=1;j<=2*i-1;j++)
            cout<<"*";
        
        
        for(int j=1;j<=n-i-1;j++)
            cout<<" ";
        
        cout<<endl;
    }
}


int main()
{
    print_pattern(5);
}
