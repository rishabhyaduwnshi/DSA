#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s1, string s2) 
{
    int i=0;
    int j=0;
    
    int s1_length = s1.length();
    int s2_length = s2.length();
    
    while(i<s1_length && j<s2_length)
    {
        if(s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
        
        if(j == s2_length)
            return true;
    }
    
    return false;
    
}


int main()
{
    string str1 = "abcdefghi";
    string str2 = "ace";
    if(isSubsequence(str1,str2))
        cout<<"Yes";
    else
        cout<<"No";
}
