#include<bits/stdc++.h>
using namespace std;

void patternSearching(string str, string pattern)
{
    int str_length = str.length();
    int pattern_length = pattern.length();
    
    for(int i=0;i<=str_length-pattern_length;i++)
    {
        int j = 0;
        for(j=0;j<pattern_length;j++)
        {
            if(pattern[j] != str[i+j])
                break;
        }
        if(j == pattern_length)
            cout<<i<<" ";
    }
}


int main()
{
    string str = "abcabcd";
    string pattern = "abcd";
    patternSearching(str,pattern);
}
