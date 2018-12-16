#include <iostream>
#include <vector>
using namespace std;
const int MAXN=2000000000;
const int MINI=-2000000000;
typedef long long int lli;
int N,M;
bool bpGraph[252][252];
bool bpm(int u, bool seen[], int matchR[])
{
    for (int v = 0; v < M; v++)
    {
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
lli maxBPM()
{
    int matchR[M];
    memset(matchR, -1, sizeof(matchR));
    lli result = 0;
    for (int u = 0; u < N; u++)
    {
        bool seen[M];
        memset(seen, 0, sizeof(seen));
        if (bpm(u, seen, matchR))
            result++;
    }
    return result;
}
lli maxMatching(vector<lli> C,vector<lli> D,lli e)
{
    memset(bpGraph,false,sizeof(bpGraph));
    for(int i=0;i<N;i++)
    {
        lli l=lower_bound(D.begin(),D.end(),C[i]-e)-D.begin();
        lli r=upper_bound(D.begin(),D.end(),C[i]+e)-D.begin();
        for(lli j=l;j<r;j++)
            bpGraph[i][j]=true;
    }
    return maxBPM();
}
int main()
{
    int t;
    lli e;
    cin>>t;
    while(t--)
    {
        cin>>N>>M>>e;
        vector<lli> C(N);
        vector<lli> F(N);
        vector<lli> D(M);
        for(int i=0;i<N;i++)
            cin>>C[i];
        for(int j=0;j<M;j++)
            cin>>D[j];
        sort(C.begin(),C.end());
        sort(D.begin(),D.end());
        lli ans = maxMatching(C,D,e);
        for(lli x=min(C[0],D[0])-e;x<=max(C[N-1],D[M-1])+e;x++)
        {
            for(int i=0;i<N;i++)
                F[i]=C[i]+x;
            ans=maxMatching(F,D,e);
            cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
