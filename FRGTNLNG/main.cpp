#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int t,n,k,l,flag;
    cin>>t;
    while(t--)
    {
        vector<string> str1,str2;
        string exp;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>exp;
            str1.push_back(exp);
        }
        for(int i=0;i<k;i++)
        {
            cin>>l;
            for(int j=0;j<l;j++)
            {
                cin>>exp;
                str2.push_back(exp);
            }
        }
        for(vector<string>::iterator i=str1.begin();i!=str1.end();i++)
        {
            flag=0;
            for(vector<string>::iterator j=str2.begin();j!=str2.end();j++)
            {
                if(*i==*j)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                cout<<"YES ";
            else
                cout<<"NO ";
        }
        cout<<endl;
    }
    return 0;
}
