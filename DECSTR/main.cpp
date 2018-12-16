#include <iostream>
using namespace std;
int main()
{
    int t;
    int K;
    string str="zyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcba";
    cin>>t;
    while(t--)
    {
        string s;
        cin>>K;
        K=K+((K-1)/25)+1;
        s.assign(str.end()-K,str.end());
        cout<<s<<endl;
    }
    return 0;
}
