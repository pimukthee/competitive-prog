#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
queue <pair<int,int> > bfs;
vector <int> adj[1005];
int ans[1005];
bool visited[1005];
int main()
{
    int T,p,d,u,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&p,&d);
        while(d--)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs.push(make_pair(0,0));
        while(!bfs.empty())
        {
            int dis = bfs.front().first,node = bfs.front().second;
            bfs.pop();
            if(!visited[node])
            {
                visited[node]=true;
                ans[node]=dis;
                for(int i=0; i<adj[node].size(); i++)
                    bfs.push(make_pair(dis+1,adj[node][i]));
            }
        }

        for(int i=1; i<p; i++)
            printf("%d\n",ans[i]);
        for(int i=0; i<=p; i++)
        {
            adj[i].clear();
            ans[i]=0;
            visited[i]=false;
        }
        if(T) printf("\n");
    }
    return 0;
}

