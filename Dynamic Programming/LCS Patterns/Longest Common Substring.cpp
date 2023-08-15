#include <bits/stdc++.h>
using namespace std;

int LCSubstring(string str1, string str2, int s1_length, int s2_length, int max_length)
{
    if(s1_length == 0 || s2_length == 0)
        return 0;
    
    int max_length1 = max_length;
    if(str1[s1_length-1] == str2[s2_length-1])
        max_length1 = LCSubstring(str1,str2,s1_length-1,s2_length-1,max_length1+1);
    
    int max_length2 = LCSubstring(str1,str2,s1_length-1,s2_length,0);
    int max_length3 = LCSubstring(str1,str2,s1_length,s2_length-1,0);
    
    return max(max_length1,max(max_length2,max_length3));
}



int main()
{
    string str1 = "ABCDGH";
    string str2 = "ACDGHR";
    int s1_length = str1.size();
    int s2_length = str2.size();
 
    cout << "Length of LCSubstring is " << LCSubstring(str1, str2, s1_length, s2_length, 0);
 
    return 0;
}
 
