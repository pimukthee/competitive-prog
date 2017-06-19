#include <cstdio>
int a[200005],gen[15];
long long ans;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        gen[a[i]]++;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=m; j++)
            if(j != a[i])
                ans+=1ll*gen[j];
        gen[a[i]]--;
    }
    printf("%I64d",ans);
    return 0;
}
