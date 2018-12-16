#include <iostream>
using namespace std;
int main()
{
    int t,n;
    char str[10];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>str[i];
        str[n]='\0';
        cout<<str<<endl;
    }
    return 0;
}
