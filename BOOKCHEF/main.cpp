#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
int main()
{
    int N,M;
    int f,p;
    string str;
    cin>>N>>M;
    map<int,bool> special;
    vector< pair<int,string> > popularitySpecial;
    vector< pair<int,string> > popularityNormal;
    for(int i=0;i<N;i++)
    {
        cin>>f;
        special[f]=true;
    }
    for(int i=0;i<M;i++)
    {
        cin>>f;
        cin>>p;
        cin>>str;
        if(special[f])
            popularitySpecial.push_back(make_pair(p,str));
        else
            popularityNormal.push_back(make_pair(p,str));
    }
    sort(popularitySpecial.begin(),popularitySpecial.end(),greater< pair<int,string> >() );
    sort(popularityNormal.begin(),popularityNormal.end(),greater< pair<int,string> >() );
    for(auto x: popularitySpecial)
        cout<<x.second<<endl;
    for(auto x: popularityNormal)
        cout<<x.second<<endl;
    return 0;
}
