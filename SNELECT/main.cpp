#include <iostream>
using namespace std;
const int MAXN=102;
int main()
{
    int t;
    char str[MAXN];
    int snakes,mongooses;
    cin>>t;
    while(t--)
    {
        snakes=mongooses=0;
        cin>>str;
        for(int i=0;str[i];i++)
        {
            if(str[i]=='m')
                mongooses++;
            else if(str[i]=='s')
            {
                if(str[i-1]!='m' && str[i+1]!='m')
                    snakes++;
                else
                {
                    if(i>0 && str[i-1]=='m')
                        str[i-1]='-';
                    else if(i<strlen(str)-1 && str[i+1]=='m')
                    {
                        str[i+1]='-';
                        mongooses++;
                    }
                }
            }
        }
        if(snakes>mongooses)
            cout<<"snakes"<<endl;
        else if(snakes<mongooses)
            cout<<"mongooses"<<endl;
        else
            cout<<"tie"<<endl;
    }
    return 0;
}
