#include <iostream>
using namespace std;
const int MAXN=41;
int main()
{
    int t,n,XOR;
    int x[MAXN],y[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        XOR=0;
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        for(int i=1;i<=n;i++)
            XOR^=i;
        cout<<XOR<<endl;
    }
    return 0;
}
