#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int K,N;
    cin>>K>>N;
    vector<string> v1(K);
    vector<string> v2(N);
    for(int i=0;i<K;i++)
        cin>>v1[i];
    for(int i=0;i<N;i++)
    {
        cin>>v2[i];
        if(v2[i].size()>=47)
        {
            cout<<"Good"<<endl;
            continue;
        }
        bool flag=false;
        for(auto str:v1)
        {
            if(v2[i].find(str)!=string::npos)
            {
                cout<<"Good"<<endl;
                flag=true;
                break;
            }
        }
        if(flag)
            continue;
        else
            cout<<"Bad"<<endl;
    }
    return 0;
}
