#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
const int MAXN = 503;
typedef unsigned long long int lli;
lli gcd(lli a,lli b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
lli lcm(lli a, lli b)
{
    return a*b/gcd(a,b);
}
int main()
{
    int t;
    int N;
    lli arr[MAXN];
    cin>>t;
    while(t--)
    {
        lli ans=LONG_LONG_MAX;
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>arr[i];
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                ans=min(ans,lcm(arr[i],arr[j]));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
