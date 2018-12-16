#include <iostream>
using namespace std;
typedef long long int lli;
int main()
{
    lli A,B;
    cin>>A>>B;
    lli diff=A-B;
    if(diff%10!=9)
        diff++;
    else
        diff--;
    cout<<diff<<endl;
    return 0;
}
