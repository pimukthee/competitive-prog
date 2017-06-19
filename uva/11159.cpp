#include <cstdio>
#include <vector>
using namespace std;
vector <int> match,vis;
vector <vector<int> > adj;
int A[105],B[105];
int Aug(int i)
{
    if(!vis[i])
    {
        vis[i]=1;
        for(int j=0; j<adj[i].size(); j++)
        {
            int k = adj[i][j];
            if(match[k]==-1||Aug(match[k]))
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
    int T,n,m;
    scanf("%d",&T);
    for(int c=1; c<=T; c++)
    {
        scanf("%d",&n);
        adj.assign(n,vector<int> ());
        for(int i=0; i<n; i++)
            scanf("%d",&A[i]);
        scanf("%d",&m);
        for(int i=0; i<m; i++)
            scanf("%d",&B[i]);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                if((A[i]==0&&B[j]==0)||(A[i]!=0&&(B[j]==0||B[j]%A[i]==0)))
                    adj[i].push_back(j+n);
        }
        int ans=0;
        match.assign(n+m,-1);
        for(int i=0; i<n; i++)
        {
            vis.assign(n,0);
            ans+=Aug(i);
        }
        printf("Case %d: %d\n",c,ans);
    }
    return 0;
}
