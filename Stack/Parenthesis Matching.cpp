#include <bits/stdc++.h>
using namespace std;

bool isMatching(char a, char b)
{
    if(a == '(' && b == ')')
        return true;
    
    if(a == '{' && b == '}')
        return true;
        
    if(a == '[' && b == ']')
        return true;
        
    return false;
}

bool validParenthesis(string parenthesis)
{
    stack<char> st;
    if(parenthesis.length() == 0)
        return true;
        
    for(int i=0;i<parenthesis.length();i++)
    {
        if(parenthesis[i] == '(' || parenthesis[i] == '{' || parenthesis[i] == '[')
            st.push(parenthesis[i]);
            
        if(st.empty() == true && (parenthesis[i] == ')' || parenthesis[i] == '}' || parenthesis[i] == ']'))
            return false;
            
        if(parenthesis[i] == ')' && st.top() != '(')
            return false;
        
        if(parenthesis[i] == '}' && st.top() != '{')
            return false;
            
        if(parenthesis[i] == ']' && st.top() != '[')
            return false;
            
        if((parenthesis[i] == ')' || parenthesis[i] == '}' || parenthesis[i] == ']'))
        {
            if(isMatching(st.top(),parenthesis[i]))
                st.pop();
        }
    }
    
    if(st.empty() == true)
        return true;
    else
        return false;
    
    
}

int main()
{
    string str = "[{()}]";
    if(validParenthesis(str))
        cout<<"Yes";
    else
        cout<<"No";
    
}
