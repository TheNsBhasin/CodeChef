#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int t,count;
    cin>>t;
    vector<string> d1,d2;
    string str;
    while(t--)
    {
        count=0;
        d1.clear();
        d2.clear();
        for(int i=0;i<4;i++)
        {
            cin>>str;
            d1.push_back(str);
        }
        for(int i=0;i<4;i++)
        {
            cin>>str;
            d2.push_back(str);
        }
        for(vector<string>::iterator i=d1.begin();i!=d1.end();i++)
        {
            for(vector<string>::iterator j=d2.begin();j!=d2.end();j++)
            {
                if(*i==*j)
                    ++count;
            }
        }
        if(count>=2)
            cout<<"similar"<<endl;
        else
            cout<<"dissimilar"<<endl;
    }
    return 0;
}
