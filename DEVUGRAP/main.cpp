#include <iostream>
using namespace std;
typedef long long int ll;
const int MAXN=100005;
int main()
{
    int t,n,k,r;
    ll ans;
    int arr[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        ans=0;
        for(int i=0;i<n;i++)
        {
            r=arr[i]%k;
            if(arr[i]>=k)
                ans+=min(r,k-r);
            else
                ans+=k-r;
        }
        cout<<ans<<endl;
    }
    return 0;
}
