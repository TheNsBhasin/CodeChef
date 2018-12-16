#include <iostream>
using namespace std;
const int MAXN=1000006;
int main()
{
    int t,n;
    int arr[MAXN],brr[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<2*n;i++)
            cin>>arr[i];
        sort(arr,arr+2*n);
        for(int i=0,k=0;i<n;i++)
        {
            brr[k]=arr[i];
            k=k+2;
        }
        for(int i=n,k=1;i<2*n;i++)
        {
            brr[k]=arr[i];
            k=k+2;
        }
        cout<<arr[3*n/2]<<endl;
        for(int i=0;i<2*n;i++)
            cout<<brr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
