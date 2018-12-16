#include <iostream>
using namespace std;
const int MAXN=105;
int main()
{
    int t,m,n,k,input,count;
    bool track[MAXN],ignore[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        count=0;
        for(int i=1;i<=n;i++)
        {
            ignore[i]=false;
            track[i]=false;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>input;
            ignore[input]=true;
        }
        for(int i=1;i<=k;i++)
        {
            cin>>input;
            track[input]=true;
        }
        for(int i=1;i<=n;i++)
        {
            if(ignore[i] && track[i])
                count++;
        }
        cout<<count<<" ";
        count=0;
        for(int i=1;i<=n;i++)
        {
            if(!ignore[i] && !track[i])
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
