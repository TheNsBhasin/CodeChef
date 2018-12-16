#include <iostream>
using namespace std;
int main()
{
    int t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        int counter=0;
        for(int i=0;str[i];i++)
        {
            if(str[i]!='4' && str[i]!='7')
                counter++;
        }
        cout<<counter<<endl;
    }
    return 0;
}
