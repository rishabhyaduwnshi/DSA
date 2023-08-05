#include<bits/stdc++.h>
using namespace std;

int leftmostRepeatingCharacter(string str) 
{
    bool visited[256];
    memset(visited,256,false);
    
    int result = -1;
    
    for(int i=str.length()-1;i>=0;i--)
    {
        if(visited[str[i]])
            result = i;
        else
            visited[str[i]] = true;
    }
    
    return result;
    
}


int leftmostRepeatingCharacter(string str) 
{
    for(int i=0;i<str.length()-1;i++)
    {
        for(int j=i+1;j<str.length();j++)
        {
            if(str[i] == str[j])
            {
                cout<<str[i]<<" ";
                return i;
            }
        }
    }
    
    return -1;
}


int main()
{
    string str = "abcdba";
    cout<<leftmostRepeatingCharacter(str);

}
