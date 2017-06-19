#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define sqr(x) x*x
#define LL long long
#define F first
#define S second
#define vi vector<int>
#define pi pair<int,int>
using namespace std;
vi group[1005];
int we[1005],be[1005],w,g=1;
int groupw,groupb;
bool visited[1005];
int dp[1005][1005];
void dfs(int i)
{
    if(!visited[i])
    {
        groupw += we[i];
        groupb += be[i];
        visited[i]=true;
        for(int j=0; j<=w; j++)
        {
            dp[g][j] = max(dp[g-1][j],dp[g][j]);
            if(j>=we[i])
                dp[g][j]=max(max(dp[g][j],dp[g][j-1]),dp[g-1][j-we[i]]+be[i]);
        }
        for(int j:group[i])
            dfs(j);
    }
}
int main()
{
    int n,m,a,b;
    scanf("%d%d%d",&n,&m,&w);
    for(int i=1; i<=n; i++)
        scanf("%d",&we[i]);
    for(int i=1; i<=n; i++)
        scanf("%d",&be[i]);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&a,&b);
        group[a].pb(b);
        group[b].pb(a);
    }
    for(int i=1; i<=n; i++)
    {
        groupw = groupb = 0;
        if(!visited[i])
        {
            dfs(i);
            for(int j=groupw; j<=w; j++)
                dp[g][j] = max(dp[g][j],dp[g-1][j-groupw]+groupb);
            g++;
        }
    }
    printf("%d",dp[g-1][w]);
    return 0;
}
