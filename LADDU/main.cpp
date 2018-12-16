#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t,activities;
    string str;
    int min_redeem,rank,severity;
    int laddu;
    cin>>t;
    while(t--)
    {
        laddu=0;
        cin>>activities>>str;
        if(str=="INDIAN")
            min_redeem=200;
        else
            min_redeem=400;
        for(int i=0;i<activities;i++)
        {
            cin>>str;
            if(str=="CONTEST_WON")
            {
                cin>>rank;
                laddu+=300+(rank<=20?(20-rank):0);
            }
            else if(str=="TOP_CONTRIBUTOR")
                laddu+=300;
            else if(str=="BUG_FOUND")
            {
                cin>>severity;
                laddu+=severity;
            }
            else
                laddu+=50;
        }
        cout<<ceil(laddu/min_redeem)<<endl;
    }
    return 0;
}
