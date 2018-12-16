#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;
int main()
{
    int N1,N2,N3;
    int x,maxi=INT_MIN;
    map<int,int> list1,list2,list3;
    vector<int> res;
    cin>>N1>>N2>>N3;
    for(int i=0;i<N1;i++)
    {
        cin>>x;
        list1[x]++;
        maxi=max(maxi,x);
    }
    for(int i=0;i<N2;i++)
    {
        cin>>x;
        list2[x]++;
        maxi=max(maxi,x);
    }
    for(int i=0;i<N3;i++)
    {
        cin>>x;
        list3[x]++;
        maxi=max(maxi,x);
    }
    for(int i=1;i<=maxi;i++)
    {
        if((list1[i] && list2[i]) || (list1[i] && list3[i]) || (list2[i] && list3[i]))
            res.push_back(i);
    }
    cout<<res.size()<<endl;
    for(auto x: res)
        cout<<x<<endl;
    return 0;
}
