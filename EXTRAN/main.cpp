#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAXI = 100005;
typedef long long int lli;
lli arr[MAXI];
int cmp(const void* a, const void* b)
{
    if( *(long long int*)a - *(long long int*)b < 0 )
        return -1;
    else if( *(long long int*)a - *(long long int*)b > 0 )
        return 1;
    else
        return 0;
}
lli extraN(int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        if(arr[i+1]-arr[i]==1)
            continue;
        break;
    }
    if(i!=0 && i+1<n && arr[i+1]-arr[i-1]!=1)
        i=i+1;
    return arr[i];
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	qsort(arr,n,sizeof(lli),cmp);
        cout<<extraN(n)<<endl;
    }
    return 0;
}
