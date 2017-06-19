#include <cstdio>
int a[1001];
int main()
{
    int n,k,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if(i!=1&&a[i]+a[i-1]<k)
        {
            int m = k-(a[i]+a[i-1]);
            ans += m;
            a[i] += m;
        }
    }
    printf("%d\n",ans);
    for(int i=1; i<=n; i++)
        printf("%d ",a[i]);
    return 0;
}
