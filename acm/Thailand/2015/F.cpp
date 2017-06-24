#include <cstdio>
#include <algorithm>
using namespace std;
double dp[1010];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=3; i<=n+2; i++)
        {
            scanf("%lf",&dp[i]);
            dp[i]=max(dp[i]+dp[i-3],dp[i-1]);
        }
        printf("%.1lf\n",dp[n+2]);
    }
    return 0;
}
