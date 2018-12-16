#include <iostream>
using namespace std;
const int MAXN=1000006;
int main()
{
    int n,arr[MAXN],flag;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        flag=1;
        for(int i=1;i<=n;i++)
        {
            if(arr[arr[i]]==i)
                continue;
            else
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"ambiguous"<<endl;
        else
            cout<<"not ambiguous"<<endl;
    }
    return 0;
}
