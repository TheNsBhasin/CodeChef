#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    unsigned long long int count,steps;
    int index1,index2;
    string str;
    stack<int> pos;
    map<int,int> m;
    cin>>t;
    while(t--)
    {
        m.clear();
        count=0;
        cin>>str;
        int len=(int)str.length();
        for(int i=len-1;i>=0;i--)
            if(str[i]=='1')
                pos.push(len-i-1);
        while(!pos.empty())
        {
            index1=pos.top();
            index2=-1;
            pos.pop();
            if(!pos.empty())
                index2=pos.top();
            m[index1]=index2;
        }
        steps=0;
        for (map<int,int>::iterator i=m.begin(); i!=m.end(); i++)
        {
            steps+=i->first-i->second-1;
            if((i->first-i->second-1)>0)
                ++steps;
            count+=steps;
        }
        cout<<count<<endl;
    }
    return 0;
}
