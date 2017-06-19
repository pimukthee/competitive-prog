#include <cstdio>
#include <algorithm>
struct a
{
    int u,v,ww;
    bool operator <(const a &w) const
    {
        return ww<w.ww;
    }
}arr[1000005];
int head[1000005];
int findhead(int x)
{
    if(head[x]==x) return x;
    return head[x]=findhead(head[x]);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n+m)
    {
        int ans=0,edge=0;
        for(int i=0; i<m; i++)
            scanf("%d%d%d",&arr[i].u,&arr[i].v,&arr[i].ww);
        std::sort(arr,arr+m);
        for(int i=0; i<=n; i++)
            head[i]=i;
        for(int i=0; i<m; i++)
        {
            int uu=findhead(arr[i].u);
            int vv=findhead(arr[i].v);
            if(uu!=vv)
            {
                head[vv]=uu;
                ans=arr[i].ww;
                edge++;
            }
        }
        if(edge==n-1)
            printf("%d\n",ans);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
