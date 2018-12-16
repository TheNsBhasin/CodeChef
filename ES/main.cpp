#include <iostream>
#include <math.h>
using namespace std;
typedef long long int lli;
int main()
{
    lli n;
    cin>>n;
    cout<<floor((exp(1)*n*((n+1)/2))-(n-1)/2)<<endl;
    return 0;
}
