#include <bits/stdc++.h>
using namespace std;

int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '/' || x == '*')
        return 2;
    else
        return 0;
}


bool isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return false;
    else
        return true;
}



void infixToPostfix(string infix_expression)
{
    string postfix_expression = "";
    stack <char> st;
    int i=0;
    st.push('#');
    
    while(infix_expression[i] != '\0')
    {
        //if current character is operand, add it to postfix_expression
        if(isOperand(infix_expression[i]))
            postfix_expression += infix_expression[i++];
        
        //if current character is an operator, check its precedence 
        else
        {
            if(precedence(infix_expression[i]) > precedence(st.top()))
                st.push(infix_expression[i++]);
            else
            {    
                postfix_expression += st.top();
                st.pop();
            }
        }
    }
    
    while(st.empty() == false)
    {
        postfix_expression += st.top();
        st.pop();
    }
    
    cout<<postfix_expression<<" ";
}

int main()
{
    string infix_expression = "a+b*c";
    infixToPostfix(infix_expression);
    
}
