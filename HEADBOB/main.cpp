#include <iostream>
using namespace std;
const int MAXN=1003;
int main()
{
    int t,n;
    char exp[MAXN];
    bool Y,I;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>exp;
        Y=I=false;
        for(int i=0;exp[i];i++)
        {
            if(exp[i]=='Y')
            {
                Y=true;
                break;
            }
            else if(exp[i]=='I')
            {
                I=true;
                break;
            }
        }
        if(Y)
            cout<<"NOT INDIAN"<<endl;
        else if(I)
            cout<<"INDIAN"<<endl;
        else
            cout<<"NOT SURE"<<endl;
    }
    return 0;
}
