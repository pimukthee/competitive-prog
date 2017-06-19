#include <cstdio>
#include <algorithm>
int v[1005];
int main()
{
    int n,k,a,b;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",&v[i]);
    int ans=0;
    while(k--)
    {
        scanf("%d%d",&a,&b);
        ans+=std::min(v[a],v[b]);
    }
    printf("%d",ans);
    return 0;
}
