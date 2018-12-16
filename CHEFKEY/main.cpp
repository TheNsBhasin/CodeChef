#include <iostream>
using namespace std;
int main()
{
    int t,n,m,c;
    int count;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>c;
        count=0;
        for(int i=1;i<=n;i++)
            if(c%i==0 && c/i<=m)
                count++;
        cout<<count<<endl;
    }
    return 0;
}
