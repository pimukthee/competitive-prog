#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#define mp make_pair
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
priority_queue<ii, vector<ii>, greater<ii> > q;
vector <int> dist;
int main()
{
    int T,n,m,s,t,u,v,dis;
    scanf("%d",&T);
    for(int c=1; c<=T; c++)
    {
        scanf("%d%d%d%d",&n,&m,&s,&t);
        vector<vector< pair<int,int> > > adj(n+1,vector< pair<int,int> > ());
        dist.assign(n+1,1000000001);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&dis);
            adj[u].push_back(mp(v,dis));
            adj[v].push_back(mp(u,dis));
        }
        q.push(mp(0,s));
        dist[s]=0;
        while(!q.empty())
        {
            u = q.top().second;
            q.pop();
            int si = adj[u].size();
            for(int i=0; i<si; i++)
            {
                v = adj[u][i].first;
                //printf("%d\n",v);
                dis = adj[u][i].second;
                if(dist[u]+dis < dist[v])
                {
                    dist[v]=dist[u]+dis;
                    q.push(mp(dist[v],v));
                }
            }
        }
        printf("Case #%d: ",c);
        if(dist[t]==1000000001)
            printf("unreachable\n");
        else
            printf("%d\n",dist[t]);
    }
    return 0;
}
