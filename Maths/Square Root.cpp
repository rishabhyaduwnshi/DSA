#include <bits/stdc++.h>
using namespace std;

int squareRoot(int number)
{
    int i = 1;
    while(i*i <= number)
        i++;
        
    return i-1;
}

int main()
{
    cout<<squareRoot(15);
}
