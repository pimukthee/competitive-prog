#include <cstdio>
#include <algorithm>
using namespace std;
int dp[5][100005];
int n,k;
int findMax(int m)
{
    int j=1,Max=0;
    for(int i=1; i<=n; i++)
    {
        int num = dp[m][i]-dp[m][j-1];
        if( num <=k)
            Max=max(num+dp[m^1][i]-dp[m^1][j-1],Max);
        else
            j++;
    }
    return Max;
}
int main()
{
    char c;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf(" %c",&c);
        dp[0][i]=dp[0][i-1];
        dp[1][i]=dp[1][i-1];
        if(c=='a')
            dp[0][i]++;
        else
            dp[1][i]++;
    }
    printf("%d",max(findMax(0),findMax(1)));
    return 0;
}
