#include <iostream>
using namespace std;
typedef long long int lli;
int main()
{
    int A,N,K;
    cin>>A>>N>>K;
    N++;
    for(int i=0;i<K;i++)
    {
        cout<<A%N<<" ";
        A=A/N;
    }
    return 0;
}
