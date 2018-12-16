#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;
const int MAXN=100005;
int main()
{
    int n,q,t;
    lli arr[MAXN];
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    while(q--)
    {
        cin>>t;
        if(t>=arr[0] && t<=arr[n-1])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
