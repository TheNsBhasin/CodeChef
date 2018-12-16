#include <iostream>
#include <stack>
using namespace std;
const int MAXN=100005;
int priority(char ch)
{
    switch(ch)
    {
        case 'C':
            return 1;
        case 'E':
            return 2;
        case 'S':
            return 3;
        default:
            return -1;
    }
}
int main()
{
    int t;
    char str[MAXN];
    cin>>t;
    while(t--)
    {
        stack<char> s;
        bool flag=true;
        cin>>str;
        for(int i=0;str[i];i++)
        {
            if(!s.empty() && priority(str[i])<priority(s.top()))
            {
                flag=false;
                break;
            }
            s.push(str[i]);
        }
        if(flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
