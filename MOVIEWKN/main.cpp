#include <iostream>
using namespace std;
const int MAXN=102;
int main()
{
    int t,n,index;
    int L[MAXN],R[MAXN],Prod[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>L[i];
        for(int i=0;i<n;i++)
            cin>>R[i];
        index=0;
        for(int i=0;i<n;i++)
            Prod[i]=L[i]*R[i];
        for(int i=1;i<n;i++)
        {
            if(Prod[i]>Prod[index])
                index=i;
            else if(Prod[i]==Prod[index])
            {
                if(R[i]>R[index])
                    index=i;
                else if(R[i]==R[index])
                    index=min(index,i);
            }
        }
        cout<<index+1<<endl;
    }
    return 0;
}
