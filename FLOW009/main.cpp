#include <iostream>
#include <iomanip>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    float quantity,total,price;
    cin>>t;
    while(t--)
    {
        cin>>quantity>>price;
        total=quantity*price;
        if(quantity>1000)
            total-=total/10;
        cout<<fixed<<setprecision(6)<<total<<endl;
    }
    return 0;
}
