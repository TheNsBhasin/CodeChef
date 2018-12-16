#include <iostream>
using namespace std;
const int MAXN=200006;
int main()
{
    int t,balance,max_balance;
    char exp1[MAXN],exp2[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>exp1;
        balance=max_balance=0;
        for(int i=0;exp1[i];i++)
        {
            if(exp1[i]=='(')
                balance=balance+1;
            if(exp1[i]==')')
                balance=balance-1;
            max_balance=max(max_balance,balance);
        }
        for(int i=0;i<max_balance;i++)
            exp2[i]='(';
        for(int i=max_balance;i<2*max_balance;i++)
            exp2[i]=')';
        exp2[2*max_balance]='\0';
        cout<<exp2<<endl;
    }
    return 0;
}
