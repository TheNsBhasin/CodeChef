#include <iostream>
using namespace std;
const int MAXN=100005;
int main()
{
    int t;
    char X[MAXN],Y[MAXN],Z[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>X>>Y;
        int i=0;
        for(i=0;X[i] && Y[i];i++)
        {
            if(X[i]^Y[i])
                Z[i]='B';
            else
                Z[i]=(X[i]=='B')?'W':'B';
        }
        Z[i]='\0';
        cout<<Z<<endl;
    }
    return 0;
}
