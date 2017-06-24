#include <cstdio>
#include <queue>
#include <utility>
#define mp make_pair
using namespace std;
queue <pair<int,int> > q;
bool vis[50][50];
char table[50][50];
void reset()
{
    for(int i=0; i<=45; i++)
    {
        for(int j=0; j<=45; j++)
        {
            table[i][j]='#';
            vis[i][j]=false;
        }

    }
}
int main()
{
    int w,h;
    while(scanf("%d%d",&w,&h)&&w+h)
    {
        reset();
        for(int i=1; i<=h; i++)
        {
            for(int  j=1; j<=w; j++)
            {
                 scanf(" %c",&table[i][j]);
                 if(table[i][j]=='P')
                    q.push(mp(i,j));
            }
        }
        int ans=0;
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(!vis[row][col])
            {
                ans++;
                vis[row][col]=true;
                if(table[row-1][col]=='.')
                    q.push(mp(row-1,col));
                if(table[row+1][col]=='.')
                    q.push(mp(row+1,col));
                if(table[row][col-1]=='.')
                    q.push(mp(row,col-1));
                if(table[row][col+1]=='.')
                    q.push(mp(row,col+1));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
