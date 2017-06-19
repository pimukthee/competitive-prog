#include <cstdio>
#include <algorithm>
using namespace std;
int dp[100005];
int main()
{
    int n,a,cur=1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a);
        if(dp[a-1]>0)
            dp[a]=dp[a-1];
        dp[a]++;
    }
    printf("%d",n-(*max_element(dp+1,dp+n+1)));
    return 0;
}
