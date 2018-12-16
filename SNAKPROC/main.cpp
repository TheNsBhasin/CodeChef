#include <iostream>
using namespace std;
bool solve(string str)
{
    int H=1,T=-1;
    int result=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]=='H')
            result+=H;
        if(str[i]=='T')
            result+=T;
        if(result<0 || result>1)
            return false;
    }
    if(result==0)
        return true;
    return false;
}
int main()
{
    int R,L;
    string str;
    cin>>R;
    while(R--)
    {
        cin>>L;
        cin>>str;
        if(solve(str))
            cout<<"Valid"<<endl;
        else
            cout<<"Invalid"<<endl;
    }
    return 0;
}
