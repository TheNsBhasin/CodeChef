#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <cstring>
using namespace std;
typedef long long int lli;
const int MAXN=100005;
lli N,Q;
lli arr[MAXN];
lli L[MAXN],R[MAXN],X[MAXN],Y[MAXN];
bool isPrime[MAXN];
vector<lli> v;
set< pair< pair<lli,lli>,lli > > expoSet;
set< pair<lli,lli> >querySet;
lli BITree[MAXN];
map<lli,map<lli,lli> > ansQuery;
void Sieve()
{
    memset(isPrime,true,sizeof(isPrime));
    for(lli i=2;i<MAXN;i++)
    {
        if(isPrime[i])
        {
            v.push_back(i);
            for(lli j=i*i;j<MAXN;j+=i)
                isPrime[j]=false;
        }
    }
}
void update(lli index,lli val)
{
    while(index<=N)
    {
        BITree[index]+=val;
        index+=index&(-index);
    }
}
lli query(lli index)
{
    lli expo=0;
    while(index>0)
    {
        expo+=BITree[index];
        index-=index&(-index);
    }
    return expo;
}
lli solve(lli L,lli R,lli X,lli Y)
{
    return (ansQuery[R][Y]-ansQuery[L][Y])-(ansQuery[R][X]-ansQuery[L][X]);
}
int main()
{
    Sieve();
    cin>>N;
    for(lli i=1;i<=N;i++)
    {
        cin>>arr[i];
        lli val=arr[i];
        for(int j=0;j<v.size();j++)
        {
            if(val<=1)
                break;
            if(isPrime[val])
            {
                expoSet.insert(make_pair(make_pair(val,i),1));
                break;
            }
            lli expo=0;
            while(val%v[j]==0)
            {
                val=val/v[j];
                expo++;
            }
            if(expo>0)
                expoSet.insert(make_pair(make_pair(v[j],i),expo));
        }
    }
    cin>>Q;
    for(lli i=1;i<=Q;i++)
    {
        cin>>L[i]>>R[i]>>X[i]>>Y[i];
        X[i]--,L[i]--;
        querySet.insert(make_pair(X[i],L[i]));
        querySet.insert(make_pair(X[i],R[i]));
        querySet.insert(make_pair(Y[i],L[i]));
        querySet.insert(make_pair(Y[i],R[i]));
    }
    memset(BITree,0,sizeof(BITree));
    for(auto qSet:querySet)
    {
        while(expoSet.size()!=0)
        {
            set< pair< pair<lli,lli>,lli > >:: iterator it=expoSet.begin();
            if((it->first).first > qSet.first)
                break;
            update((it->first).second,it->second);
            expoSet.erase(it);
        }
        lli ans=query(qSet.second);
        ansQuery[qSet.second][qSet.first]=ans;
    }
    for(lli i=1;i<=Q;i++)
        cout<<solve(L[i],R[i],X[i],Y[i])<<endl;
    return 0;
}
