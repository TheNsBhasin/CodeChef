#include <iostream>
using namespace std;
const int MAXN=100005;
typedef long long int lli;
int main()
{
    int t;
    lli n;
    lli arr[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<n*(n-1)/2<<endl;
    }
    return 0;
}
