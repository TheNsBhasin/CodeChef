#include <iostream>
using namespace std;
typedef long long int lli;
lli C(lli n,lli k)
{
    lli C[k+1];
    memset(C, 0, sizeof(C));
    C[0]=1;
    for (lli i=1;i<=n;i++)
        for (lli j=min(i,k);j>0;j--)
            C[j]=C[j]+C[j-1];
    return C[k];
}
int main()
{
    int t,n,m;
    char A[11][11];
    lli collisions,count;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        collisions=0;
        for(int i=0;i<n;i++)
            cin>>A[i];
        for(int i=0;i<m;i++)
        {
            count=0;
            for(int j=0;j<n;j++)
            {
                if(A[j][i]=='1')
                    count++;
            }
            if(count>1)
                collisions+=C(count,2);
        }
        cout<<collisions<<endl;
    }
    return 0;
}
