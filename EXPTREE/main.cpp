#include <iostream>
using namespace std;
typedef long long int lli;
const int MOD1=1e9 + 7;
const int MOD2=1e9 + 9;
lli modInverse(lli a, lli m)
{
    lli m0 = m, t, q;
    lli x0 = 0, x1 = 1;
    
    if (m == 1)
        return 0;
    
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    
    if (x1 < 0)
        x1 += m0;
    
    return x1;
}
int main()
{
    int t;
    lli n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        lli ans1 = ((n%MOD1)*((n-1)%MOD1))%MOD1;
        lli modInverse1 = modInverse(2*(2*n-3), MOD1)%MOD1;
        ans1=((ans1%MOD1)*(modInverse1%MOD1))%MOD1;
        lli ans2 = ((n%MOD2)*((n-1)%MOD2))%MOD2;
        lli modInverse2 = modInverse(2*(2*n-3), MOD2)%MOD2;
        ans2=((ans2%MOD2)*(modInverse2%MOD2))%MOD2;
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
