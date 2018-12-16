#include <iostream>
using namespace std;
const int MAXN=1000006;
int main()
{
    int t,n,k,sum;
    int arr[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            sum=sum%2;
        }
        if(sum%2==0 && k==1)
            cout<<"odd"<<endl;
        else
            cout<<"even"<<endl;
    }
    return 0;
}
