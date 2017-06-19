#include <cstdio>
#include <algorithm>
using namespace std;
int dp[105][105],a[105],b[105];
int main()
{
    int n,m,c=1;
    while(scanf("%d%d",&n,&m)&&n+m)
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(int i=1; i<=m; i++)
            scanf("%d",&b[i]);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                dp[i][j]=0;
                if(a[i]==b[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",c++,dp[n][m]);
    }
    return 0;
}
