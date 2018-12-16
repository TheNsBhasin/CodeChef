#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t;
    double p = 0.0,s = 0.0,c,b,x,first,second,a,v;
    cin>>t;
    while(t--)
    {
        scanf("%lf %lf",&p,&s);
        c = s/6 ;
        b = -1*(p/6);
        x = sqrt((b*b)-(4*c));
        first = ((p/6) + x)/2;
        second = ((p/6) - x)/2;
        if((6*first)<(p/2)){
            a = (p/4 - first);
            a = first*first*a;
            v = (s*first/2) - a;
            printf("%0.2f\n",v);
        }
        else
        {
            a = (p/4 - second);
            a = second*second*a;
            v = (s*second/2) - a;
            printf("%0.2f\n",v);
        }
    }
    return 0;
}
