#include <iostream>
using namespace std;
const int MAXI=100005;
typedef long long int lli;
lli x[MAXI],y[MAXI];
int main()
{
    int t,n,j,k;
    lli first,second;
    cin>>t;
    while(t--)
    {
    	j=0,k=1;
    	first=second=0;
    	cin>>n;
    	for(int i=0;i<n;i++)
    		cin>>x[i];
    	for(int i=0;i<n;i++)
    		cin>>y[i];
    	for(int i=0;i<n;i++)
    	{
    		if(j==0)
    			first+=x[i];
    		else
    			first+=y[i];
    		j=(j+1)%2;
    		if(k==0)
    			second+=x[i];
    		else
    			second+=y[i];
    		k=(k+1)%2;
    	}
        cout<<min(first,second)<<endl;
    }
    return 0;
}
