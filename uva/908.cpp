#include <cstdio>
#include <set>
using namespace std;
struct a
{
    int u,v,cost;
    bool operator <(const a &w) const
    {
        return cost<w.cost;
    }
}temp;
int head[1000005];
int findhead(int x)
{
    if(head[x]==x) return x;
    return head[x]=findhead(head[x]);
}
int main()
{
    int n,f,t,c,uu,vv,ans1,ans2,k,m,flag=0;
    while(scanf("%d",&n)>0)
    {
        ans1=ans2=0;
        for(int i=1; i<n; i++)
        {
            scanf("%d%d%d",&f,&t,&c);
            ans1+=c;
        }
        scanf("%d",&k);
        multiset <a> comp;
        multiset <a> ::iterator it;
        for(int i=0; i<=n; i++)
            head[i]=i;
        while(k--)
        {
            scanf("%d%d%d",&temp.u,&temp.v,&temp.cost);
            comp.insert(temp);
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d",&temp.u,&temp.v,&temp.cost);
            comp.insert(temp);
        }
        for(it=comp.begin(); it!=comp.end(); it++)
        {
            uu=findhead(it->u);
            vv=findhead(it->v);
            if(uu!=vv)
            {
                head[vv]=uu;
                ans2+=it->cost;
            }
        }
        if(flag) printf("\n");
        flag=1;
        printf("%d\n%d\n",ans1,ans2);
    }
    return 0;
}
