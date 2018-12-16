#include <iostream>
using namespace std;
int main()
{
    int t;
    int N;
    cin>>t;
    while(t--)
    {
        cin>>N;
        if(N%4==1)
            cout<<"ALICE"<<endl;
        else
            cout<<"BOB"<<endl;
    }
    return 0;
}
