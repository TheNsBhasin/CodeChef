#include <iostream>
using namespace std;
typedef long long int ll;
const int MAXN = 10004;
int main()
{
    int t,n,count;
    ll A[MAXN],B[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        A[0]=0;
        count=0;
        for (int i=1; i<=n; i++)
            cin>>A[i];
        for (int i=1; i<=n; i++)
            cin>>B[i];
        for(int i=1;i<=n;i++)
            if(A[i]-A[i-1]>=B[i])
                count++;
        cout<<count<<endl;
    }
    return 0;
}
