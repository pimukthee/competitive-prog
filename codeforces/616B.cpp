#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,m,col,ans=-1000000005,k;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        col=1000000005;
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&k);
            col=min(col,k);
        }
        ans=max(ans,col);
    }
    printf("%d",ans);
    return 0;
}
