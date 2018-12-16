#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int t,n,k;
    int case1,case2,count;
    cin>>t;
    while(t--)
    {
        string str;
        vector<int> block;
        vector<int>::iterator it;
        cin>>n>>k;
        cin>>str;
        case1=case2=0;
        for(int i=0;i<n;i++)
        {
            if(i%2)
            {
                if(str[i]=='1')
                    case1++;
                else
                    case2++;
            }
            else
            {
                if(str[i]=='0')
                    case1++;
                else
                    case2++;
            }
        }
        if(min(case1,case2)<=k)
        {
            cout<<1<<endl;
            continue;
        }
        count=1;
        for(int i=1;i<n;i++)
        {
            if(str[i]==str[i-1])
                count++;
            else
            {
                block.push_back(count);
                count=1;
            }
        }
        block.push_back(count);
        int l=2,r=n;
        while(l<r)
        {
            int mid=(l+r)/2;
            int need=0;
            for(it=block.begin();it!=block.end();it++)
                need+=*it/(mid+1);
            if(need<=k)
                r=mid;
            else
                l=mid+1;
        }
        cout<<l<<endl;
    }
}
