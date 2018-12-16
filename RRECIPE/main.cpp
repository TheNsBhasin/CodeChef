#include <iostream>
#include <math.h>
using namespace std;
const int MOD=10000009;
typedef unsigned long long int lli;
int main()
{
    int t,n;
    string str;
    lli ans;
    cin>>t;
    while(t--)
    {
        ans=1;
        cin>>str;
        n=(int)str.length();
        for(int i=0;i<ceil((double)n/2);i++)
        {
            if(str[i]!=str[n-i-1])
            {
                if(str[i]!='?' && str[n-i-1]!='?')
                {
                    ans=0;
                    break;
                }
            }
            else
            {
                if(str[i]=='?')
                    ans=(ans*26)%MOD;
            }
        }
        cout<<ans%MOD<<endl;
    }
    return 0;
}
