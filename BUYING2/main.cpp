#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int t;
    int N,X;
    int arr[102];
    cin>>t;
    while(t--)
    {
        int mini=INT_MAX;
        int sum=0;
        cin>>N>>X;
        for(int i=0;i<N;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            mini=min(mini,arr[i]);
        }
        if(mini>sum%X)
            cout<<sum/X<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
