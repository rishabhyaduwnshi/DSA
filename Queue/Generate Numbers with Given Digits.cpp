#include <bits/stdc++.h>
using namespace std;

void generateNumbersWithGivenDigits(int n)
{
    queue<string> qu;
    qu.push("5");
    qu.push("6");
    
    for(int count=0;count<=n;count++)
    {
        string current = qu.front();
        cout<<current<<endl;
        qu.pop();
        qu.push(current + "5");
        qu.push(current + "6");
    }
}

int main()
{
    generateNumbersWithGivenDigits(10);
    
}
