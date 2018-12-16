#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    int up,down;
    int N;
    string str;
    cin>>t;
    while(t--)
    {
        up=down=0;
        cin>>str;
        N = (int)str.length();
        for(int i=0;i<N-1;i++)
        {
            if(str[i+1]==str[i])
                continue;
            else
                str[i]=='U'?up++:down++;
        }
        str[N-1]=='U'?up++:down++;
        if(up<down)
            cout<<up<<endl;
        else
            cout<<down<<endl;
    }
    return 0;
}
