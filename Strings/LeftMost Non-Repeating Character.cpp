#include<bits/stdc++.h>
using namespace std;

int leftmostNonRepeatingCharacter(string str) 
{
    int visited[256];
    memset(visited,256,false);
    int result = -1;
    for(int i=str.length()-1;i>=0;i--)
        visited[str[i]]++;
        
    for(int i=0;i<256;i++)
    {
        if(visited[str[i]] == 1)
            return i;
    }
    return result;
}

int main()
{
    string str = "abcdab";
    cout<<leftmostNonRepeatingCharacter(str);

}
