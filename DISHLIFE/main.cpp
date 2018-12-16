#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
class ComparisonClass
{
public:
    bool operator()(vector<int> v1, vector<int> v2)
    {
        if(v1.size()<v2.size())
            return true;
        return false;
    }
};
int main()
{
    int t,n,k;
    int num,ingredient;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        priority_queue< vector<int>,vector<vector<int> >, ComparisonClass  > q;
        set<int> s;
        vector<int> v;
        int flag=0;
        bool skip=false;
        for(int i=0;i<n;i++)
        {
            v.clear();
            cin>>num;
            for(int i=0;i<num;i++)
            {
                cin>>ingredient;
                v.push_back(ingredient);
            }
            q.push(v);
        }
        while(!q.empty())
        {
            if(s.size()==k)
            {
                if(!q.empty())
                    skip=true;
                flag=1;
                break;
            }
            v=q.top();
            for(vector<int>::iterator it=v.begin();it!=v.end();it++)
                s.insert(*it);
            q.pop();
        }
        if(s.size()==k)
        {
            if(skip)
                cout<<"some"<<endl;
            else
                cout<<"all"<<endl;
        }
        else
            cout<<"sad"<<endl;
    }
    return 0;
}
