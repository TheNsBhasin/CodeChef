#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int t;
    int N;
    int arr[102];
    int totalSum,mini;
    cin>>t;
    while(t--)
    {
        totalSum=0;
        mini=INT_MAX;
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>arr[i];
        for(int i=0;i<N;i++)
        {
            totalSum+=arr[i];
            mini=min(mini,arr[i]);
        }
        cout<<totalSum-N*mini<<endl;
    }
    return 0;
}
