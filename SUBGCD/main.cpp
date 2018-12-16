#include <iostream>
#include <climits>
using namespace std;
typedef long long int lli;
const int MAXN=100005;
lli gcd(lli a,lli b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}
int main()
{
    int t,n;
    lli arr[MAXN];
    lli g;
    cin>>t;
    while(t--)
    {
        cin>>n;
        g=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            g=gcd(arr[i],g);
        }
        if(g==1)
            cout<<n<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
