#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int MAXN=102;
int main()
{
    int t,n,ans;
    int d[MAXN];
    bool arr[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=0;i<=100;i++)
            arr[i]=false;
        for(int i=0;i<n;i++)
        {
            cin>>d[i];
            if(arr[d[i]]==false)
            {
                arr[d[i]]=true;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
