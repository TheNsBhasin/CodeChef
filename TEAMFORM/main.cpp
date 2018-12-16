#include <iostream>
using namespace std;
int main()
{
    int t,n,m;
    int u,v;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<m;i++)
            cin>>u>>v;
        if((n-2*m)%2)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
    return 0;
}
