#include <iostream>
using namespace std;
const int MAXN=102;
int main()
{
    int t,chef,comp;
    char score[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>score;
        chef=comp=0;
        for(int i=0;score[i];i++)
        {
            if(score[i]=='1')
                chef++;
            else
                comp++;
        }
        if(chef>comp)
            cout<<"WIN"<<endl;
        else
            cout<<"LOSE"<<endl;
    }
    return 0;
}
