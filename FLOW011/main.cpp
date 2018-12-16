#include <iostream>
using namespace std;
int main()
{
    int t;
    float basic,HRA,DA;
    cin>>t;
    while (t--)
    {
        cin>>basic;
        if(basic<1500)
        {
            HRA=basic/10;
            DA=basic*9/10;
        }
        else
        {
            HRA=500;
            DA=basic*98/100;
        }
        cout<<basic+HRA+DA<<endl;
    }
    return 0;
}
