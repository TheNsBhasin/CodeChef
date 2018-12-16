#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
    int n,a,b,total_pts1=0,total_pts2=0,max_lead1=INT_MIN,max_lead2=INT_MIN;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        total_pts1+=a;
        total_pts2+=b;
        if(total_pts1-total_pts2>max_lead1)
            max_lead1=total_pts1-total_pts2;
        else if(total_pts2-total_pts1>max_lead2)
            max_lead2=total_pts2-total_pts1;
    }
    if(max_lead1>max_lead2)
        cout<<"1"<<" "<<max_lead1<<endl;
    else if(max_lead2>max_lead1)
        cout<<"2"<<" "<<max_lead2<<endl;
    return 0;
}
