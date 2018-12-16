#include <iostream>
#include <queue>
using namespace std;
bool check[1003];
int main()
{
    int t,n,m,ind;
    cin>>t;
    while(t--)
    {
        queue<int> chef,assi;
        int temp;
        cin>>n>>m;
        memset(check,false,sizeof(bool)*(n+1));
        while(m--)
        {
            cin>>ind;
            check[ind]=true;
        }
        temp=0;
        for(int i=1;i<=n;i++)
        {
            if(check[i]==false)
            {
                temp%=2;
                if(temp==0)
                    chef.push(i);
                else
                    assi.push(i);
                temp++;
            }
        }
        while(!chef.empty())
        {
            ind=chef.front();
            cout<<ind<<" ";
            chef.pop();
        }
        cout<<endl;
        while(!assi.empty())
        {
            ind=assi.front();
            cout<<ind<<" ";
            assi.pop();
        }
        cout<<endl;
    }
    return 0;
}
