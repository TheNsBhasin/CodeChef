#include <iostream>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    lli U,V;
    cin>>t;
    while(t--)
    {
        cin>>U>>V;
        cout<<(((U+V+1)*(U+V))/2)+U+1<<endl;
    }
    return 0;
}
