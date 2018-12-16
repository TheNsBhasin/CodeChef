#include <iostream>
using namespace std;
int main() 
{
	int t,n,prevZero=0,fine=0;
	cin>>t;
	while(t--)
	{
		prevZero=fine=0;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=0;i<n;i++)
		{
			if(arr[i]==0)
			{
				prevZero=1;
				fine+=1100;
			}
			else
			{
				if(prevZero==0)
					continue;
				else
					fine+=100;
			}
		}
		cout<<fine<<endl;
	}
    return 0;
}
