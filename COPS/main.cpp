#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=12;
int main()
{
    int t,m,x,y,ans,k;
    int arr[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>m>>x>>y;
        ans=0;
        k=x*y;
        for(int i=0;i<m;i++)
            cin>>arr[i];
        sort(arr,arr+m);
        if(arr[0]-k>1)
            ans+=arr[0]-k-1;
        for(int i=0;i<m-1;i++)
            if(arr[i+1]-arr[i]>2*k)
                ans+=arr[i+1]-arr[i]-2*k-1;
        if(arr[m-1]+k<100)
            ans+=100-(arr[m-1]+k);
        cout<<ans<<endl;
    }
    return 0;
}
