#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) 
{
    int i=0;
    int j=s.length()-1;


    while(i<=j)
    {
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
        return true;   
}


int main()
{
    string str = "abccba";
    if(isPallindrome(str))
        cout<<"Yes";
    else
        cout<<"No";
}
