#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int MAXN=52;
typedef long long int lli;
int main()
{
    int t,n;
    bool flag;
    vector<string> str(MAXN);
    stack<string> s;
    cin>>t;
    while(t--)
    {
        flag=true;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>str[i];
        for(int i=0;i<n;i++)
        {
            if(str[i]=="cookie" && (str[i+1]!="milk" || i+1>=n))
            {
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
