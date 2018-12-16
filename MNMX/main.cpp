#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+10;
int arr[MAXN];
int t, n;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
            scanf("%d", &arr[i]);
        sort(arr, arr+n);
        printf("%lld\n", 1ll*arr[0]*(n-1));
    }
    return 0;
}
