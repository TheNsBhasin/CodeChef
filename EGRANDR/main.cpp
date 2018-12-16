#include <iostream>
using namespace std;
const int MAXN=100005;
int main()
{
    int t,n;
    int A[MAXN];
    cin>>t;
    while(t--)
    {
        bool mask=true,full=false;
        double avg=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            if(A[i]<=2)
                mask=false;
            if(A[i]==5)
                full=true;
            avg+=A[i];
        }
        avg=(double)avg/n;
        if(avg<4.0)
            mask=false;
        if(mask && full)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
