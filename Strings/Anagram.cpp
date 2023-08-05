#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2) 
{
    int charArray[26] = {0};
    for(int i=0;i<s1.length();i++)
    {
        charArray[s1[i-'a']]++;
        charArray[s1[i-'a']]--;
    }
    
    for(int i=0;i<26;i++)
    {
        if(charArray[i] != 0)
            return false;
    }
    
    
    return true;
}


int main()
{
    string str1 = "cae";
    string str2 = "ace";
    if(isAnagram(str1,str2))
        cout<<"Yes";
    else
        cout<<"No";
}
