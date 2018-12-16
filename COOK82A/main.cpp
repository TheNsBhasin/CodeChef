#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    int t;
    string str;
    int s;
    cin>>t;
    while(t--)
    {
        map<string,int> scores;
        for(int i=0;i<4;i++)
        {
            cin>>str>>s;
            scores[str]=s;
        }
        if((scores["RealMadrid"] < scores["Malaga"]) && (scores["Barcelona"] > scores["Eibar"]))
            cout<<"Barcelona"<<endl;
        else
            cout<<"RealMadrid"<<endl;
            
    }
    return 0;
}
