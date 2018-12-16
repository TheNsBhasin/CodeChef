#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t,n;
    int index;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<n<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<n<<endl;
            index=i;
            for(int j=1;j<=n;j++,index++)
            {
                cout<<j<<" "<<(index%n)+1<<" "<<((index+1)%n)+1<<endl;
            }
        }
    }
    return 0;
}
