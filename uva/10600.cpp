#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#define mp make_pair
using namespace std;
vector <int> head(110);
vector <bool> mark(15000);
vector <pair<int,pair<int,int> > > G;
int findhead(int x)
{
    if(x==head[x]) return x;
    return head[x] = findhead(head[x]);
}
int MST(int m,int n,int ignore)
{
    int cnt =0,sum=0;
    for(int i=0; i<m && cnt<n-1 ; i++)
    {
        int u = findhead(G[i].second.first);
        int v = findhead(G[i].second.second);
        if(i!=ignore && u!=v)
        {
            sum += G[i].first;
            head[v]=u;
            if(ignore==-1)
                mark[i] = true;
            cnt++;
        }
    }
    return cnt==n-1?sum:1000000000;
}
int main()
{
    int T,n,m,a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        mark.assign(15000,false);
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n; i++) head[i]=i;
        G.clear();
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            G.push_back(mp(c,mp(a,b)));
        }
        sort(G.begin(),G.end());
        int ans1 =  MST(m,n,-1),ans2=1000000000;
        for(int i=0; i<m; i++)
        {
            for(int i=0; i<=n; i++) head[i]=i;
            if(mark[i])
            {
                int temp = MST(m,n,i);
                ans2 = min(ans2,temp);
                //printf("%d %d\n",i,temp);
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
