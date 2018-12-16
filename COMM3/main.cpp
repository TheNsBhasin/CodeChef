#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t,r,x1,y1,x2,y2,x3,y3,dist1,dist2,dist3;
    cin>>t;
    while(t--)
    {
        cin>>r;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        dist1=pow((x1-x2),2)+pow((y1-y2),2);
        dist2=pow((x1-x3),2)+pow((y1-y3),2);
        dist3=pow((x2-x3),2)+pow((y2-y3),2);
        if((dist1<=pow(r,2) && dist2<=pow(r,2)) || (dist1<=pow(r,2) && dist3<=pow(r,2)) || (dist2<=pow(r,2) && dist3<=pow(r,2)))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
