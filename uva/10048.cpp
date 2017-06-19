#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node
{
    int from,to,sound;
    bool operator <(const node &w) const
    {
        return sound < w.sound;
    }
}arr[1005],temp;
int head[105];
int findhead(int x)
{
    if(x==head[x]) return x;
    return head[x]=findhead(head[x]);
}

vector <int> adj[105];
int visited[105];
int dis[105][105];
queue <node> bfs;
void init()
{
    for(int i=0; i<105; i++)
    {
        adj[i].clear();
        head[i]=i;
        visited[i]=0;
    }

}
int main()
{
    int c,s,q,u,v,cc=0,ans;
    while(scanf("%d%d%d",&c,&s,&q)&&c+s+q!=0)
    {
        init();
        for(int i=0; i<s; i++)
            scanf("%d%d%d",&arr[i].from,&arr[i].to,&arr[i].sound);
        sort(arr,arr+s);
        for(int i=0; i<s; i++)
        {
            int uu = arr[i].from,vv = arr[i].to;
            u = findhead(uu);
            v = findhead(vv);
            if(u!=v)
            {
                head[u]=v;
                adj[uu].push_back(vv);
                adj[vv].push_back(uu);
                dis[uu][vv]=dis[vv][uu]=arr[i].sound;
            }
        }
        if(cc) printf("\n");
        printf("Case #%d\n",++cc);
        for(int i=1; i<=q; i++)
        {
            scanf("%d%d",&u,&v);
            temp.from=u;
            temp.sound=0;
            bfs.push(temp);
            while(!bfs.empty())
            {
                temp = bfs.front();
                u = temp.from;
                if(u==v) break;
                bfs.pop();
                if(visited[u]!=i)
                {//printf("%d ",u);
                    visited[u]=i;
                    for(int j=0; j<adj[u].size(); j++)
                    {
                        int k = adj[u][j];
                        temp.from = k;
                        temp.sound = max(temp.sound,dis[u][k]);
                        bfs.push(temp);
                    }
                }
            }
            if(!bfs.empty())
                printf("%d\n",temp.sound);
            else
                printf("no path\n");
            while(!bfs.empty()) bfs.pop();
        }
    }
    return 0;
}
