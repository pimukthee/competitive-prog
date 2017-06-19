#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
double gx[105],gy[105],hx[105],hy[105];
vector <int> match,vis;
vector <vector<int> >adj;
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
double dist(int i,int j)
{
    return sqrt((gx[i] - hx[j]) * (gx[i] - hx[j])+ (gy[i] - hy[j]) * (gy[i] - hy[j]));
}
int main()
{
    int n,m,s,v;
    while(scanf("%d%d%d%d",&n,&m,&s,&v)>0)
    {
        adj.assign(n+m,vector <int> () );
        for(int i=0; i<n; i++)
            scanf("%lf%lf",&gx[i],&gy[i]);
        for(int i=0; i<m; i++)
            scanf("%lf%lf",&hx[i],&hy[i]);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                 //printf("%lf\n",dist(i, j) / (1.0*v));
                 if(1.0*s>(dist(i,j)/(1.0*v)))
                    adj[i].push_back(n+j);
            }

        int ans=0;
        //printf("%d\n\n",adj[1].size());
        match.assign(n+m,-1);
        for(int i=0; i<n; i++)
        {
            vis.assign(n,0);
            ans+=Aug(i);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
