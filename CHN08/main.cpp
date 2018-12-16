#include <iostream>
using namespace std;
typedef long long int lli;
const lli MOD = 1000000007;
int main()
{
    int t;
    lli N;
    lli arr[7];
    cin>>t;
    while(t--)
    {
        cin>>arr[1]>>arr[2]>>N;
        arr[1]=arr[1]%MOD;
        arr[2]=arr[2]%MOD;
        arr[1]=(arr[1]<0)?arr[1]+MOD:arr[1];
        arr[2]=(arr[2]<0)?arr[2]+MOD:arr[2];
        arr[3]=(arr[2]-arr[1])%MOD;
        arr[3] = arr[3] < 0 ? arr[3] + MOD : arr[3];
        arr[4]=(arr[3]-arr[2])%MOD;
        arr[4] = arr[4] < 0 ? arr[4] + MOD : arr[4];
        arr[5]=(arr[4]-arr[3])%MOD;
        arr[5] = arr[5] < 0 ? arr[5] + MOD : arr[5];
        arr[6]=(arr[5]-arr[4])%MOD;
        arr[6] =(arr[6] < 0)?arr[6] + MOD : arr[6];
        if((N%6)==0)
            cout<<arr[6]<<endl;
        else
            cout<<arr[(N%6)]<<endl;
    }
    return 0;
}
