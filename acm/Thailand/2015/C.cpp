#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
queue <pair<int,int> > q;
vector <vector<int> > adj;
vector <int> dis;
vector <bool> vis;
int main()
{
    int T,C,M,a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&C,&M);
        dis.assign(C+5,0);
        adj.assign(C+5,vector<int>() );
        vis.assign(C+5,false);
        while(--C)
        {
            scanf("%d%d%d",&a,&b,&c);
            dis[b]+=c;
            adj[a].push_back(b);
        }
        q.push(make_pair(1,1));
        while(!q.empty())
        {
            a = q.front().first;
            b = q.front().second;
            q.pop();
            if(!vis[b])
            {
                dis[b]+=dis[a];
                vis[b]=true;
                for(int i=0; i<adj[b].size(); i++)
                    q.push(make_pair(b,adj[b][i]));
            }
        }
        int k = *max_element(dis.begin(),dis.end());
        printf("%d\n",k>=M?k:-1);
    }
    return 0;
}
