#include <cstdio>
#include <queue>
using namespace std;
queue <int> q;
int ans[200005],a[200005];
void check(int cur,int dis)
{
    if(!ans[cur] && cur!=1)
    {
        ans[cur]=dis;
        q.push(cur);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    q.push(1);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        check(a[cur],ans[cur]+1);
        if(cur > 1) check(cur-1,ans[cur]+1);
        if(cur < n) check(cur+1,ans[cur]+1);
    }
    for(int i=1; i<=n; i++)
        printf("%d ",ans[i]);
    return 0;
}
