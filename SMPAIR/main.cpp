#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=1000006;
int main()
{
    int t,n,arr[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        cout<<arr[0]+arr[1]<<endl;
    }
    return 0;
}
