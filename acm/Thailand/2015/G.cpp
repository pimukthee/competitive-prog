#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector <int> deg;
vector <vector<int> > adj;
vector <bool> vis;
queue <int> q;
int euler;
void bfs(int m)
{
    q.push(m);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(!vis[u])
        {
            vis[u]=true;
            if(deg[u]&1)
                euler++;
            for(int i=0; i<adj[u].size(); i++)
                q.push(adj[u][i]);
        }
    }
}
int main()
{
    int T,n,m,a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        adj.assign(n,vector<int> ());
        deg.assign(n,0);
        vis.assign(n,false);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            deg[a]+=c;
            deg[b]+=c;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int cnt=0;
        euler=0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i]&&adj[i].size()>0)
            {
                if(cnt==0)
                    bfs(i);
                cnt++;
            }
        }
        if(cnt>1 || euler>2)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}
/*5
3
3 0 1 1 0 2 1 1 2 1
3
2 0 1 1 0 2 2
4
2 0 1 2 2 3 2
3
1 0 2 3
2
0
*/
