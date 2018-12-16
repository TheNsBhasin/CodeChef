#include <iostream>
using namespace std;
typedef long long int ll;
int main()
{
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a<b)
            cout<<"<"<<endl;
        else if(a==b)
            cout<<"="<<endl;
        else
            cout<<">"<<endl;
    }
    return 0;
}
