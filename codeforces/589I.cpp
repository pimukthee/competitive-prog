#include <cstdio>
int arr[1005];
int main()
{
    int n,k,m,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&m);
        arr[m]++;
    }
    for(int i=1; i<=k; i++)
    {
        if(arr[i]> n/k )
            ans+=arr[i]-n/k;
    }
    printf("%d",ans);
    return 0;
}
