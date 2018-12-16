#include <iostream>
using namespace std;
const int MAXN=100005;
typedef long long int lli;
int main()
{
    lli N,D;
    int arr[MAXN];
    cin>>N>>D;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    sort(arr,arr+N);
    int counter=0;
    for(int i=0;i<N-1;i++)
    {
        if(abs(arr[i]-arr[i+1])<=D)
        {
            counter++;
            i++;
        }
    }
    cout<<counter<<endl;
    return 0;
}
