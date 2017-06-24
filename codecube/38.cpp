#include <cstdio>
#include <queue>
#include <cstring>
#include <utility>
#define mp make_pair
using namespace std;
queue <pair<pair<int,int>,int> > bfs;
int up[1005][1005],down[1005][1005],right[1005][1005],left[1005][1005],floor[1005][1005];
int visited[1005][1005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&floor[i][j]);
            visited[i][j]=1000000000;
        }
    }
    for(int i=1; i<=n; i++)
    {
        right[i][n+1]=n+1;
        for(int j=n; j>=1; j--)
        {
            if(floor[i][j])
                right[i][j]=j;
            else
                right[i][j]=right[i][j+1];
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(floor[i][j])
                left[i][j]=j;
            else
                left[i][j]=left[i][j-1];
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(floor[j][i])
                up[j][i]=j;
            else
                up[j][i]=up[j-1][i];
        }
    }
    for(int i=1; i<=n; i++)
    {
        down[n+1][i]=n+1;
        for(int j=n; j>=1; j--)
        {
            if(floor[j][i])
                down[j][i]=j;
            else
                down[j][i]=down[j+1][i];
        }
    }
   // printf("%d\n\n",right[8][9]);
    bfs.push(mp(mp(1,1),0));
    while(!bfs.empty())
    {
        int a = bfs.front().first.first;
        int b = bfs.front().first.second;
        int c = bfs.front().second;
        bfs.pop();

        if(visited[a][b]>c)
        {
            visited[a][b]=c;
            bfs.push(mp(mp(a,right[a][b]-1),c+right[a][b]-1-b));
            bfs.push(mp(mp(a,left[a][b]+1),c+b-left[a][b]-1));
            bfs.push(mp(mp(up[a][b]+1,b),c+a-up[a][b]-1));
            bfs.push(mp(mp(down[a][b]-1,b),c+down[a][b]-1-a));
        }
    }
    printf("%d",visited[n][n]);
    return 0;
}
