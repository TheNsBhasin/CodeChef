#include <iostream>
using namespace std;
int main()
{
    int t,n,day;
    cin>>t;
    while(t--)
    {
        cin>>n;
        day=0;
        if(n>2001)
        {
            for(int i=2001;i<n;i++)
            {
                if((i%4==0)&&(i%400==0||i%100!=0))
                    day+=2;
                else
                    day+=1;
            }
            day=day%7;
        }
        else
        {
            for(int i=n;i<2001;i++)
            {
                if((i%4==0)&&(i%400==0||i%100!=0))
                    day+=2;
                else
                    day+=1;
            }
            day=(day%7==0)?0:7-(day%7);
        }
        switch (day)
        {
            case 0:
                cout<<"monday"<<endl;
                break;
            case 1:
                cout<<"tuesday"<<endl;
                break;
            case 2:
                cout<<"wednesday"<<endl;
                break;
            case 3:
                cout<<"thursday"<<endl;
                break;
            case 4:
                cout<<"friday"<<endl;
                break;
            case 5:
                cout<<"saturday"<<endl;
                break;
            case 6:
                cout<<"sunday"<<endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
