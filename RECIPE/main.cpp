#include <iostream>
#include <limits.h>
using namespace std;
const int MAXN=50;
int GCD(int a,int b)
{
    if (a == 0)
        return b;
    return GCD(b%a,a);
}
int main()
{
    int t,n,gcd;
    int arr[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        gcd=arr[0];
        for(int i=1;i<n;i++)
            gcd=GCD(gcd,arr[i]);
        for(int i=0;i<n;i++)
            cout<<arr[i]/gcd<<" ";
        cout<<endl;
    }
    return 0;
}
