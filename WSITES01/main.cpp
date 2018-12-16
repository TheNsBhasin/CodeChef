#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    char ch;
    map<char,vector<string> > blocked;
    map<char,vector<string> > unblocked;
    string str;
    bool flag;
    int len = 1,max_len=1,blocked_size=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ch;
        cin>>str;
        if(ch=='+')
            unblocked[str.at(0)].push_back(str);
        else
            blocked[str.at(0)].push_back(str);
    }
    for(map<char,vector<string> >::iterator i=blocked.begin();i!=blocked.end();i++)
    {
        sort((i->second).begin(),(i->second).end());
        for(vector<string>:: iterator j=(i->second).begin();j!=(i->second).end();j++)
        {
            max_len=1;
            if(unblocked.find(i->first)!=unblocked.end())
            {
                for(vector<string>:: iterator k=unblocked.at(i->first).begin();k!=unblocked.at(i->first).end();k++)
                {
                    flag=true;
                    for(len=1;len<(*j).length() && len<(*k).length();len++)
                    {
                        if((*j).at(len)!=(*k).at(len))
                        {
                            flag=false;
                            break;
                        }
                    }
                    if(flag)
                    {
                        if((*k).length()<(*j).length())
                            max_len=len+1;
                        else
                        {
                            cout<<-1<<endl;
                            return 0;
                        }
                    }
                    len++;
                    max_len=max(max_len,len);
                }
            }
            *j=(*j).substr(0,max_len);
        }
        (i->second).erase(unique((i->second).begin(), (i->second).end()), (i->second).end());
        blocked_size+=(i->second).size();
    }
    cout<<blocked_size<<endl;
    for(map<char,vector<string> >::iterator i=blocked.begin();i!=blocked.end();i++)
    {
        for(vector<string>:: iterator j=(i->second).begin();j!=(i->second).end();j++)
            cout<<*j<<endl;
    }
    return 0;
}
