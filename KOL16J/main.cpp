#include <iostream>
#include <set>
using namespace std;
const int MAXN=102;
typedef long long int lli;
int main()
{
    int t,n;
    int chap;
    bool assigned[MAXN];
    bool flag1,flag2;
    cin>>t;
    while(t--)
    {
        flag1=false;
        flag2=true;
        cin>>n;
        memset(assigned,false,n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>chap;
            if(!flag1 && chap!=i)
                flag1=true;
            if(chap>n || assigned[chap]==true)
                flag2=false;
            else
                assigned[chap]=true;
        }
        if(flag1 && flag2)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
