#include <iostream>
using namespace std;
const int MAXN=102;
int main()
{
    int N,M,K;
    int E[MAXN][MAXN];
    int u,v;
    double avg=0;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin>>E[i][j];
        }
    }
    cin>>K;
    for(int i=0;i<K;i++)
    {
        cin>>u>>v;
        
    }
    return 0;
}
