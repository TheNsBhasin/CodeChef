#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long int lli;
lli solve(vector< pair<lli,lli> > vec,lli low,lli high)
{
    sort(vec.begin(),vec.end());
    lli covered=low,max_val=low,cost=0;
    for(const auto& pos:vec)
    {
        if(pos.first>covered)
        {
            covered=max_val;
            if(pos.first-1>covered)
                return -1;
            ++cost;
        }
        max_val=max(max_val,pos.second);
    }
    if(max_val>covered)
    {
        covered=max_val;
        ++cost;
    }
    if(covered<high)
        return -1;
    return cost;
}
int main()
{
    int t;
    lli N,K,M;
    lli low,high;
    lli x1,y1,x2,y2;
    lli h_cost,v_cost;
    cin>>t;
    while(t--)
    {
        cin>>N>>K>>M;
        vector< pair<lli,lli> > H,V;
        low=(N-K)/2;
        high=low+K;
        for(int i=0;i<M;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            x1--,y1--,x2--,y2--;
            if(x1>x2)
                swap(x1,x2);
            if(y1>y2)
                swap(y1,y2);
            if(!(x2<low || x1>=high))
                H.push_back(make_pair(max(x1,low),min(x2+1,high)));
            if(!(y2<low || y1>=high))
                V.push_back(make_pair(max(y1,low),min(y2+1,high)));
        }
        h_cost=solve(H,low,high);
        v_cost=solve(V,low,high);
        if(h_cost<0 || v_cost<0)
            cout<<-1<<endl;
        else
            cout<<(h_cost+v_cost)<<endl;
    }
    return 0;
}
