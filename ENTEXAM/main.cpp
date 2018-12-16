#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;
const int MAXN=100005;
int main()
{
    int t;
    lli N,K,E,M;
    lli score,total;
    lli arr[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>N>>K>>E>>M;
        for(int i=0;i<N-1;i++)
        {
            total=0;
            for(int j=0;j<E;j++)
            {
                cin>>score;
                total+=score;
            }
            arr[i]=total;
        }
        total=0;
        for(int j=0;j<E-1;j++)
        {
            cin>>score;
            total+=score;
        }
        sort(arr,arr+N-1);
        score=max(0LL,arr[N-K-1]-total+1);
        if(score<=M)
            cout<<score<<endl;
        else
            cout<<"Impossible"<<endl;
    }
    return 0;
}
