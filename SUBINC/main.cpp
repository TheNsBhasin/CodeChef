#include <iostream>
using namespace std;
typedef long long int ll;
const int MAXN=100005;
int main()
{
    ll t,n,count,len;
    ll arr[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        len=1;
        count=0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i+1]>=arr[i])
                len++;
            else
            {
                count+=((len*(len+1))/2);
                len=1;
            }
        }
        count+=((len*(len+1))/2);
        cout<<count<<endl;
    }
    return 0;
}
