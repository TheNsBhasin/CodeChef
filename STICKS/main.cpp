#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> a(n);
        vector< pair < int, int > > v;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a.rbegin(),a.rend());
        for(int i=0;i<n-1;i++)
        {
            if(a[i]==a[i+1])
            {
                v.push_back(make_pair(a[i], a[i+1]));
                ++i;
            }
        }
        if(v.size()<2)
        {
            cout<<"-1"<<endl;
            continue;
        }
        cout<<v[0].first*v[1].first<<endl;
    }
    return 0;
}
