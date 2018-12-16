#include <iostream>
using namespace std;
int main()
{
    int t;
    int N,C,Q;
    int L,R;
    cin>>t;
    while(t--)
    {
        cin>>N>>C>>Q;
        for(int i=0;i<Q;i++)
        {
            cin>>L>>R;
            if(L<=C && C<=R)
                C=L+(R-C);
        }
        cout<<C<<endl;
    }
    return 0;
}
