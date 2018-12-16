#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int MAXN=10004;
int main()
{
    int t,n,k;
    int arr[MAXN];
    float sum;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        sum=0;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        for(int i=k;i<n-k;i++)
            sum+=arr[i];
        cout<<fixed<<sum/(n-2*k)<<endl;
    }
    return 0;
}
