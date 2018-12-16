#include <iostream>
using namespace std;
int solve(string str)
{
    int n=(int)str.length();
    int count=0,cons=0;
    for(int i=0;i<n;i++)
        if(str[i]=='1')
            count++;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='1')
        {
            while(i<n && str[i]=='1')
            {
                cons++;
                i++;
            }
            break;
        }
    }
    return (count>0) && (count==cons);
}
int main()
{
    int t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        if(solve(str))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
