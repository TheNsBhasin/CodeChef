#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
typedef long long int lli;
#define INF INT_MAX //Infinity

const int sz=1000006; //Maximum possible number of vertices. Preallocating space for DataStructures accordingly
vector<pair<int,int> > a[sz]; //Adjacency list
int dis[sz]; //Stores shortest distance
bool vis[sz]={0}; //Determines whether the node has been visited or not
class prioritize
{
public:
    bool operator()(pair<int, int>&p1 ,pair<int, int>&p2)
    {
        return p1.second>p2.second;
    }
};
void Dijkstra(int source, int n) //Algorithm for SSSP
{
    for(int i=0;i<sz;i++) //Set initial distances to Infinity
        dis[i]=INF;
    //Custom Comparator for Determining priority for priority queue (shortest edge comes first)
    priority_queue<pair<int,int> ,vector<pair<int,int> >, prioritize> pq; //Priority queue to store vertex,weight pairs
    pq.push(make_pair(source,dis[source]=0)); //Pushing the source with distance from itself as 0
    while(!pq.empty())
    {
        pair<int, int> curr=pq.top(); //Current vertex. The shortest distance for this has been found
        pq.pop();
        int cv=curr.first,cw=curr.second; //'cw' the final shortest distance for this vertex
        if(vis[cv]) //If the vertex is already visited, no point in exploring adjacent vertices
            continue;
        vis[cv]=true;
        for(int i=0;i<a[cv].size();i++) //Iterating through all adjacent vertices
            if(!vis[a[cv][i].first] && a[cv][i].second+cw<dis[a[cv][i].first]) //If this node is not visited and the current parent node distance+distance from there to this node is shorted than the initial distace set to this node, update it
                pq.push(make_pair(a[cv][i].first,(dis[a[cv][i].first]=a[cv][i].second+cw))); //Set the new distance and add to priority queue
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,K,X,M,S;
        int x,y,z;
        cin>>V>>K>>X>>M>>S;
        for(int i=0;i<=V;i++)
        {
            a[i].clear();
            dis[i]=INF;
            vis[i]=0;
        }
        for(int i=0;i<K;i++)
        {
            for(int j=i+1;j<K;j++)
            {
                a[i].push_back(make_pair(j,X));
                a[j].push_back(make_pair(i,X));
            }
        }
        for(int i=0;i<M;i++)
        {
            cin>>x>>y>>z;
            a[x-1].push_back(make_pair(y-1,z));
            a[y-1].push_back(make_pair(x-1,z));
        }
        Dijkstra(S-1,V);
        for(int i=0;i<V;i++)//Printing final shortest distances from source
        {
            dis[i]!=INF? cout<<dis[i]<<" " : cout<<"-1 ";
        }
        cout<<endl;
    }
    return 0;
}
