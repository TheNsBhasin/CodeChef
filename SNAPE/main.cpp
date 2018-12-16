#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t,base,left;
    float min_right,max_right;
    cin>>t;
    while(t--)
    {
        cin>>base>>left;
        min_right=sqrt((left*left)-(base*base));
        max_right=sqrt((left*left)+(base*base));
        cout<<min_right<<" "<<max_right<<endl;
    }
    return 0;
}
