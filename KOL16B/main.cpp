#include <iostream>
#include <math.h>
using namespace std;
typedef unsigned long long int lli;
const int MAXN = 10004;
int main()
{
    int t,test=1;
    int n;
    lli num;
    lli A[MAXN],B[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            A[i]=num&((1<<16)-1);
            num=num>>16;
            B[i]=num;
        }
        cout<<"Case "<<test<<":"<<endl;
        for(int i=0;i<n;i++)
            cout<<A[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<B[i]<<" ";
        cout<<endl;
        test++;
    }
    return 0;
}
