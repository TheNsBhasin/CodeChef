#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t,n,k,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ans=0;
        for(int i=2;i<=k;i++)
            if(n%i>ans)
                ans=n%i;
        cout<<ans<<endl;
    }
    return 0;
}
