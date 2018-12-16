#include <iostream>
#include <math.h>
using namespace std;
typedef long long int lli;
const int MAXN=100005;
int main()
{
    int t,n;
    lli H[MAXN];
    lli L[MAXN],R[MAXN];
    lli sum;
    cin>>t;
    while(t--)
    {
        sum=0;
        memset(L,false,sizeof(L));
        memset(L,false,sizeof(R));
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>H[i];
            sum+=H[i];
        }
        L[0]=R[n-1]=1;
        for(int i=1;i<n;i++)
        {
            if(H[i]>L[i-1])
                L[i]=L[i-1]+1;
            else
                L[i]=H[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(H[i]>R[i+1])
                R[i]=R[i+1]+1;
            else
                R[i]=H[i];
        }
        lli max_height=-1;
        for(int i=0;i<n;i++)
            max_height=max(max_height,min(L[i],R[i]));
        cout<<sum-(max_height*max_height)<<endl;
    }
    return 0;
}
