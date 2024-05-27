/*

1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1

*/

#include <bits/stdc++.h>
using namespace std;

void print_pattern(int n, int m)
{
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=m-i+1;j++)
        {
            cout<<j<<" ";
        }
        
        cout<<endl;
    }
}


int main()
{
    print_pattern(5,5);
}
