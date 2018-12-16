#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t,n,flag;
    cin>>t;
    while(t--)
    {
        cin>>n;
        flag=1;
        for(int i=2;i<sqrt(n);i++)
        {
            if(n%i==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
