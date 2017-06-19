#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
pair <int,pair<int,int> > arr[500005];
int head[50005];
int findhead(int x)
{
    if(x==head[x]) return x;
    return head[x]=findhead(head[x]);
}
vector <pair<int,int> > adj[50005];
bool visited[50005];
int dis[50005];
queue <pair<int,int> > bfs;
int main()
{
    int c,s,q,u,v,cc=0,cost;
    scanf("%d%d",&c,&s);
    for(int i=0; i<=c; i++)
        head[i]=i;
    for(int i=0; i<s; i++)
        scanf("%d%d%d",&arr[i].second.first,&arr[i].second.second,&arr[i].first);
    sort(arr,arr+s);
    for(int i=0; i<s; i++)
    {
        int uu = arr[i].second.first,vv = arr[i].second.second;
        u = findhead(uu);
        v = findhead(vv);
        if(u!=v)
        {
            head[u]=v;
            adj[uu].push_back(make_pair(vv,arr[i].first));
            adj[vv].push_back(make_pair(uu,arr[i].first));
        }
    }
    bfs.push(make_pair(1,0));
    while(!bfs.empty())
    {
        u = bfs.front().first;
        cost = bfs.front().second;
        if(u==c) break;
        bfs.pop();
        if(!visited[u])
        {
            visited[u]=true;
            for(int j=0; j<adj[u].size(); j++)
            {
                int k = adj[u][j].first;
                bfs.push(make_pair(k,max(adj[u][j].second,cost)));
            }
        }
    }
    if(!bfs.empty())
        printf("%d\n",cost);
    else
        printf("NO PATH EXISTS\n");
    return 0;
}
