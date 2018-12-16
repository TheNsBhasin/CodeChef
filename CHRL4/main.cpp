#include <iostream>
#include <math.h>
#include <queue>
#include <utility>
using namespace std;
typedef long long int lli;
const int MAXN = 100005;
const int MOD = 1000000007;
int main()
{
    int N,K;
    lli arr[MAXN];
    lli ans[MAXN];
    double dp[MAXN];
    priority_queue< pair<double,int> > pq;
    cin>>N>>K;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    dp[0]=log(arr[0]);
    ans[0]=arr[0]%MOD;
    pq.push(make_pair(-dp[0],0));
    for(int i=1;i<N;i++)
    {
        while((i-pq.top().second)>K)
            pq.pop();
        dp[i]=dp[pq.top().second] + log(arr[i]);
        ans[i]=((ans[pq.top().second]%MOD)*(arr[i]%MOD))%MOD;
        pq.push(make_pair(-dp[i],i));
    }
    cout<<ans[N-1]<<endl;
    return 0;
}
