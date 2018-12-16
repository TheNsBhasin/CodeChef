#include <iostream>
using namespace std;
const int MAXN=102;
int main()
{
    int t,n,k;
    int arr[MAXN];
    int votes[MAXN];
    int count;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            votes[i]=0;
        count=0;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            votes[arr[i]]++;
        }
        for(int i=1;i<=n;i++)
            if(votes[i]>=k && arr[i]!=i)
                count++;
        cout<<count<<endl;
    }
    return 0;
}
