#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> match,vis;
vector <vector<int> > adj;
int Aug(int i)
{
    if(!vis[i])
    {
        vis[i]=1;
        for(int j=0; j<adj[i].size(); j++)
        {
            int k = adj[i][j];
            if(match[k]==-1 || Aug(match[k]))
            {
                match[k]=i;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int T,n,m,k,a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        adj.assign(n+m+1,vector<int>() );
        for(int i=0; i<k; i++)
        {
            scanf("%d%d",&a,&b);
            if(b<a)
                std::swap(a,b);
            adj[a].push_back(b);
        }
        int ans=0;
        match.assign(n+m+1,-1);
        for(int i=1; i<=n; i++)
        {
            vis.assign(n+1,0);
            ans+=Aug(i);
        }
        printf("%d\n",n+m-ans);
    }
    return 0;
}
