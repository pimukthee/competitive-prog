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
#define MAXN 100005
using namespace std;
vi adj[MAXN];
int ans,m,a[MAXN];
bool visited[MAXN];
void dfs(int prev,int cur,int cat)
{
    if(!visited[cur] && cat <=m)
    {
        visited[cur] = true;
        if(adj[cur].size() == 1 && adj[cur][0] == prev)
        {
            ans++;
        }

        for(int i: adj[cur])
            dfs(cur,i,cat*a[i]+a[i]);
    }
}
int main()
{
    int n,x,y;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<n; i++)
    {
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(-1,1,a[1]);
    printf("%d",ans);
    return 0;
}
