#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <limits.h>
using namespace std;
int main()
{
    int N,M;
    int u,v;
    cin>>N>>M;
    vector< pair<int,int> > edges(M);
    vector<int> cost(N);
    for(int i=0;i<N;i++)
        cin>>cost[i];
    for(int i=0;i<M;i++)
    {
        cin>>u>>v;
        edges[i]=make_pair(u,v);
    }
    if(N<=2)
        cout<<0<<endl;
    else
    {
        cout<<N-2<<endl;
        for(int i=1;i<=N;i++)
        {
            if(i!=edges[M-1].first && i!=edges[M-1].second)
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
