#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
int isOperand(char op)
{
    return (op>='a'&& op<='z')||(op>='A' && op<='Z');
}
int precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '%':
        case '$':
        case '^':
            return 3;
        default:
            return -1;
    }
}
void infixToPrefix(char* exp)
{
    int k=-1;
    stack<char> s;
    for(int i=0;exp[i];i++)
    {
        if(isOperand(exp[i]))
            exp[++k]=exp[i];
        else if(exp[i]=='(')
            s.push(exp[i]);
        else if(exp[i]==')')
        {
            while(s.top()!='(' && !s.empty())
            {
                exp[++k]=s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(!s.empty() && precedence(exp[i])<=precedence(s.top()))
            {
                exp[++k]=s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }
    while(!s.empty())
    {
        exp[++k]=s.top();
        s.pop();
    }
    exp[++k]='\0';
}
int main()
{
    int t;
    char exp[400];
    cin>>t;
    while(t--)
    {
        cin>>exp;
        infixToPrefix(exp);
        cout<<exp<<endl;
    }
    return 0;
}
