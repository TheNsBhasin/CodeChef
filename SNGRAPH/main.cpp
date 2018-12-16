#include <iostream>
#include <vector>
using namespace std;
const int MAXN=100005;
vector<int> adj[MAXN],V[MAXN];
int deg[MAXN],ans[MAXN],p[MAXN],size[MAXN];
int components;
bool active[MAXN];
int parent(int x)
{
    if(p[x]!=x)
        p[x]=parent(p[x]);
    return p[x];
}
void dsu(int a,int b)
{
    int p1=parent(a);
    int p2=parent(b);
    if(p1==p2)
        return;
    if(size[p1]<size[p2])
        swap(p1,p2);
    size[p1]+=size[p2];
    p[p2]=p1;
    components--;
}
void clear()
{
    for(int i=0;i<MAXN;i++)
    {
        adj[i].clear();
        V[i].clear();
        deg[i]=0;
        active[i]=false;
    }
}
int main()
{
    int t;
    int n,m,u,v;
    cin>>t;
    while(t--)
    {
        clear();
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++,deg[v]++;
        }
        components=n;
        for(int i=1;i<=n;i++)
        {
            p[i]=i,size[i]=1;
            V[deg[i]].push_back(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=components-1;
            for(auto u: V[i])
                active[u]=true;
            for(auto u:V[i])
            {
                for(auto v:adj[u])
                {
                    if(!active[v])
                        continue;
                    dsu(u,v);
                }
            }
        }
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}
