#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;
const int MAXN=100005;
lli S[MAXN];
lli L,A,B;
lli score(lli pos,lli N)
{
    lli score=0;
    for(int i=0;i<N;i++)
        score+=abs(S[i]-(pos+(i*L)));
    return score;
}
lli binary_search(lli low,lli high,lli N)
{
    while(low<high)
    {
        lli mid=low+(high-low)/2;
        if(score(mid,N)<score(mid+1,N))
            high=mid;
        else
            low=mid+1;
    }
    return high;
}
int main()
{
    lli t,N;
    lli max_len,pos;
    cin>>t;
    while(t--)
    {
        cin>>N>>L>>A>>B;
        for(int i=0;i<N;i++)
            cin>>S[i];
        sort(S,S+N);
        max_len=N*L;
        pos=binary_search(A,B-max_len,N);
        cout<<score(pos,N)<<endl;
    }
    return 0;
}
