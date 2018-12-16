#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long int lli;
const int MOD = 1e18;
int main()
{
    lli N,K;
    vector<double> arr(30);
    double lim,sum=0,ans=0;
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        arr[i]=log(arr[i]);
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr.begin(),next(arr.begin(),N));
    lim=log(K);
    cout<<"lim = "<<lim<<endl;
    lli n=lower_bound(arr.begin(),next(arr.begin(),N),lim)-arr.begin();
    cout<<n<<endl;
    for(lli i=0;i<n;i++)
        sum+=arr[i];
    if(sum<=lim)
        ans=pow(2,n)-1;
    
    return 0;
}
