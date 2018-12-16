#include <iostream>
using namespace std;
int main()
{
    int t,n,XOR,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        XOR=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            XOR^=x;
        }
        cout<<XOR<<endl;
    }
    return 0;
}
