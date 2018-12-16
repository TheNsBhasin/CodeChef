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
        if(360%N==0)
            cout<<"y ";
        else
            cout<<"n ";
        if(N<=360)
            cout<<"y ";
        else
            cout<<"n ";
        if(N<=26)
            cout<<"y ";
        else
            cout<<"n ";
    }
    return 0;
}
