#include <stdio.h>
int main()
{
    long long int t,n,k,count=0;
    scanf("%lld %lld",&t,&k);
    while(t--)
    {
        scanf("%lld",&n);
        if(n%k==0)
            count++;
    }
    printf("%lld\n",count);
    return 0;
}
