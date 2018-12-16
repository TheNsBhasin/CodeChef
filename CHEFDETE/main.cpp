#include <iostream>
using namespace std;
const int MAXN=100005;
int main()
{
    int n;
    int R[MAXN];
    bool killer[MAXN];
    cin>>n;
    for(int i=1;i<=n;i++)
        killer[i]=true;
    for(int i=1;i<=n;i++)
    {
        cin>>R[i];
        killer[R[i]]=false;
    }
    for(int i=1;i<=n;i++)
        if(killer[i])
            cout<<i<<" ";
    return 0;
}
