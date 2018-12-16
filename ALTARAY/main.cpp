#include <iostream>
using namespace std;
const int MAXN=100005;
int main()
{
    int t,n;
    int arr[MAXN],len[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        len[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if((arr[i]>0 && arr[i+1]<0) || (arr[i]<0 && arr[i+1]>0))
                len[i]=len[i+1]+1;
            else
                len[i]=1;
        }
        for(int i=0;i<n;i++)
            cout<<len[i]<<" ";
        cout<<endl;
    }
    return 0;
}
