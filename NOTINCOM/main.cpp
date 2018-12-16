#include <iostream>
#include <set>
using namespace std;
typedef long long int lli;
int main()
{
    int t,n,m;
    int num;
    set<int> s;
    cin>>t;
    while(t--)
    {
        s.clear();
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            s.insert(num);
        }
        for(int i=0;i<m;i++)
        {
            cin>>num;
            s.insert(num);
        }
        cout<<(n+m-s.size())<<endl;
    }
    return 0;
}
