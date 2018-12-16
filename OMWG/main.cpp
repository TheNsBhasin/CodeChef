#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cout<<m*(n-1)+n*(m-1)<<endl;
    }
    return 0;
}
