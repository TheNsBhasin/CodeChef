#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long int lli;
const int MAXN = 100005;
lli binomial_coef(lli n, lli k)
{
    lli C[k+1];
    memset(C,0,sizeof(C));
    C[0]=1;
    for(lli i=1;i<=n;i++)
    {
        for(lli j=min(i,k);j>0;j--)
            C[j]=C[j]+C[j-1];
    }
    return C[k];
}
int main()
{
    int t,n;
    char str[MAXN];
    lli ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>str;
        ans=0;
        lli counter=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='1')
                counter++;
        }
        ans+=counter;
        ans+=binomial_coef(counter,2);
        cout<<ans<<endl;
    }
    return 0;
}
