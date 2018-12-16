#include <iostream>
#include <vector>
using namespace std;
const int MAXN=100005;
int main()
{
    int t,n;
    char arr[2][MAXN];
    vector<int> r;
    bool flag1,flag2;
    int counter;
    cin>>t;
    while(t--)
    {
        r.clear();
        counter=0;
        flag1=flag2=false;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[0][i];
            if(arr[0][i]=='*')
                flag1=true;
        }
        for(int i=0;i<n;i++)
        {
            cin>>arr[1][i];
            if(arr[1][i]=='*')
                flag2=true;
        }
        if(flag1 && flag2)
            counter++;
        for(int i=0;i<n;i++)
        {
            if(arr[0][i]=='*' && arr[1][i]!='*')
                r.push_back(1);
            else if(arr[0][i]!='*' && arr[1][i]=='*')
                r.push_back(2);
            else if(arr[0][i]=='*' && arr[1][i]=='*')
                r.push_back(3);
        }
        int c=0;
        for(int i=0;i<r.size();i++)
        {
            if((r[i]==1 && r[i+1]==2) || (r[i]==2 && r[i+1]==1))
                i++;
            c++;
        }
        if(c>0)
            counter+=c-1;
        cout<<counter<<endl;
    }
    return 0;
}
