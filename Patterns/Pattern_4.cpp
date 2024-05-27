/*
1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5
*/

#include <bits/stdc++.h>
using namespace std;

void print_pattern(int n, int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<i<<" "; //printing the row number
        }
        
        cout<<endl;
    }
}


int main()
{
    print_pattern(5,5);
}


