#include<iostream>
int main()
{
    long long int total,val,sum,n;
    scanf("%lld",&n);
    sum=(n*(n+1))/2;
    total=0;
    while(n--)
    {
        scanf("%lld",&val);
        total=total+(val);
        if(total>sum)
        {
            printf("NO");
            return 0;
        }
    }
    if(total==sum)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
