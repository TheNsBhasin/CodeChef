#include <iostream>
#include <set>
using namespace std;
const int MAXN=100005;
int main()
{
    int t;
    bool flag;
    cin>>t;
    while(t--)
    {
        char str[MAXN];
        cin>>str;
        set<char> c;
        for(int i=0;str[i];i++)
            c.insert(str[i]);
        flag=true;
        for(int i=0;i<strlen(str)-1;i++)
        {
            if(str[i]==str[i+1])
            {
                flag=false;
                break;
            }
        }
        if(c.size()==2 && flag==true)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
