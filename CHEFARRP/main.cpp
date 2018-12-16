#include <iostream>
using namespace std;
typedef long long int ll;
int const MAXN=52;
int main()
{
    int t,n;
    ll arr[MAXN],sum,prod,count;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sum=prod=0;
        count=n;
        for(int i=0;i<n-1;i++)
        {
            sum=prod=arr[i];
            for(int j=i+1;j<n;j++)
            {
                sum+=arr[j];
                prod*=arr[j];
                if(sum==prod)
                    count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
