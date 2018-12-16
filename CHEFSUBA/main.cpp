#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
const int MAXN=100005;
void getMaxLength(int arr[],int brr[], int n,int k)
{
    int count=0;
    for(int i=0;i<k;i++)
        if(arr[i]==1)
            count++;
    brr[0]=count;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]==0 && arr[(k+i-1)%n]==1)
            count++;
        else if(arr[i-1]==1 && arr[(k+i-1)%n]==0)
            count--;
        brr[i]=count;
    }
}
void KMax(int brr[],int arr[], int n, int k)
{
    deque<int> Qi(k);
    int j=0;
    for (int i = 0; i < k; ++i)
    {
        while ( (!Qi.empty()) && brr[i] >= brr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    for (int i=k; i<n+k; ++i)
    {
        arr[j++]=brr[Qi.front()%n];
        while ((!Qi.empty()) && Qi.front()<=i-k)
            Qi.pop_front();
        while ( (!Qi.empty()) && brr[i%n] >= brr[Qi.back()%n])
            Qi.pop_back();
        Qi.push_back(i);
    }
    arr[j++]=brr[Qi.front()%n];
}
int main()
{
    int n,k,p;
    int arr[MAXN],brr[MAXN];
    char str[MAXN];
    int l;
    cin>>n>>k>>p;
    if(k>n)
        k=n;
    l=0;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>str;
    getMaxLength(arr,brr,n,k);
    KMax(brr,arr,n,n-k+1);
    for(int i=0;str[i];i++)
    {
        if(str[i]=='!')
        {
            l--;
            if(l<0)
                l=n-1;
        }
        else
        {
            cout<<arr[l]<<endl;
        }
    }
    return 0;
}
