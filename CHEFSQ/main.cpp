#include <iostream>
using namespace std;
const int MAXN=1003;
int main()
{
    int t,n,m,flag;
    int a[MAXN],b[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        cin>>m;
        for(int i=0;i<m;i++)
            cin>>b[i];
        flag=0;
        int j=0;
        for(int i=0;i<=n;i++)
        {
            if(a[i]==b[j])
                j++;
            if(j==m)
                flag=1;
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
