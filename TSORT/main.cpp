#include <iostream>
using namespace std;
const int MAXN=1000006;
int main()
{
    int n,arr[MAXN];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
    return 0;
}
