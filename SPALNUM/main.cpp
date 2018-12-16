#include <iostream>
using namespace std;
const int MAXN=1000006;
typedef long long int ll;
ll sum[MAXN];
void preprocess()
{
    ll n,rev;
    sum[0]=0;
    for(ll i=1;i<=1000000;i++)
    {
        n=i;
        rev=0;
        while(n)
        {
            rev=(rev*10)+(n%10);
            n/=10;
        }
        if(rev==i)
            sum[i]=sum[i-1]+i;
        else
            sum[i]=sum[i-1];
    }
}
int main()
{
    preprocess();
    ll t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
    return 0;
}
