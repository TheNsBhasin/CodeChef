#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    int t;
    string str;
    vector<string> tokens;
    cin>>t;
    getchar();
    while(t--)
    {
        tokens.clear();
        getline(cin,str);
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        istringstream iss(str);
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter(tokens));
        if(tokens.size()==1)
        {
            tokens[0].at(0)=toupper(toupper(tokens[0].at(0)));
        }
        else if(tokens.size()==2)
        {
            tokens[0].at(0)=toupper(tokens[0].at(0));
            tokens[0]=tokens[0].substr(0,1);
            tokens[0]+=".";
            tokens[1].at(0)=toupper(toupper(tokens[1].at(0)));
        }
        else
        {
            tokens[0].at(0)=toupper(tokens[0].at(0));
            tokens[0]=tokens[0].substr(0,1);
            tokens[0]+=".";
            tokens[1].at(0)=toupper(tokens[1].at(0));
            tokens[1]=tokens[1].substr(0,1);
            tokens[1]+=".";
            tokens[2].at(0)=toupper(toupper(tokens[2].at(0)));
        }
        for(string s:tokens) {
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}
