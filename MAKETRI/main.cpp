#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;
typedef long long int ll;
int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}
int main()
{
    ll n,l,r;
    cin>>n>>l>>r;
    ll len[n];
    ll result=0;
    ll sum=LONG_MIN,diff=LONG_MAX;
    for(int i=0;i<n;i++)
        cin>>len[i];
    qsort(len,n,sizeof(len[0]),cmp);
    sum=len[n-1]+len[n-2];
    for(ll i=n-1;i>=1;i--)
        diff=min(diff,len[i]-len[i-1]);
    if(diff<l && sum>r && diff<r && sum>l)
        result=r-l+1;
    else if(diff>l && sum<r && diff<r && sum>l)
        result=sum-diff-1;
    else if(diff>l && sum>r && diff<r && sum>l)
        result=r-diff;
    else if(diff<l && sum<r && diff<r && sum>l)
        result=sum-l;
    else if((diff==l && sum>r  && sum>l) || (diff<l && sum==r && diff<r))
        result=r-l;
    else if((diff==l && sum<r && sum>l) || (diff>l && sum==r && diff<r))
        result=sum-diff-1;
    else if(diff==l && sum==r)
        result=r-l-1;
    else if(diff<=l && sum<=l)
        result=0;
    else if(diff>=r && sum>=r)
        result=0;
    cout<<result<<endl;
    return 0;
}
