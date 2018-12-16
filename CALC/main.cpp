#include <iostream>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    lli N,B;
    lli ans;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>N>>B;
        ans=((N/B+1)/2L);
        ans=(N-(ans*B))*ans;
        cout<<ans<<endl;
    }
    return 0;
}
