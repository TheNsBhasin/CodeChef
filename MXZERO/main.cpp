#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int MAXN=100005;
int main()
{
    int t,n,ans,XOR,one,zero;
    int arr[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        one=zero=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]==1)
                one++;
            else
                zero++;
        }
        XOR=arr[0];
        for(int i=1;i<n;i++)
            XOR^=arr[i];
        if(XOR==0)
            ans=zero;
        else
            ans=one;
        cout<<ans<<endl;
    }
    return 0;
}
