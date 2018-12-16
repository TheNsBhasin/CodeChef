#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t;
    int A,B;
    int n1,n2;
    cin>>t;
    while(t--)
    {
        cin>>A>>B;
        n1=(int)sqrt(A);
        n2=(int)(sqrt(4*B+1)-1)>>1;
        if(n1>n2)
            cout<<"Limak"<<endl;
        else
            cout<<"Bob"<<endl;
    }
    return 0;
}
