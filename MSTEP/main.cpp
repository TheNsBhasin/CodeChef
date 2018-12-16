#include <iostream>
using namespace std;
typedef long long int ll;
const int MAXN = 505;
struct cood
{
    int x,y;
};
int main()
{
    int t,n;
    ll A[MAXN][MAXN],dist;
    struct cood M[MAXN*MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>A[i][j];
                M[A[i][j]].x=i;
                M[A[i][j]].y=j;
            }
        }
        dist=0;
        for (int i=2; i<=n*n; i++)
            dist+=abs(M[i].x-M[i-1].x)+abs(M[i].y-M[i-1].y);
        cout<<dist<<endl;
    }
    return 0;
}
